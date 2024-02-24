#include <algorithm>
#include <vector>

using namespace std;

int cmp_val;

bool cmp(vector<int> a, vector<int> b){
    if(a[cmp_val]<=b[cmp_val]) return true;
    else return false;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    int k;
    if(ext == "date") k = 1;
    else if(ext == "maximum") k = 2;
    else if( ext == "remain") k = 3;
    else k = 0;
    
    vector<vector<int>> filter;
    for(int i=0; i<data.size(); i++)
        if(data[i][k] < val_ext) filter.push_back(data[i]);
    
    if(sort_by == "date") cmp_val = 1;
    else if(sort_by == "maximum") cmp_val = 2;
    else if(sort_by == "remain") cmp_val = 3;
    else cmp_val = 0;
    
    sort(filter.begin(), filter.end(), cmp);
    return filter;
}
