void applyReplace(int lo, int hi, int& val, pair<bool,int> delta)
{
    auto [flag, newVal]=delta;
    if(flag==true) val=newVal;
}
 
void mergeReplace(int lo, int hi, pair<bool,int>& delta1, pair<bool,int> delta2)
{
    auto [flag, newVal]=delta2;
    if(flag==true) delta1=delta2;
}
 