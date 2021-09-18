/*
**  /adm/simul_efun/sum_array.c
**  
**  Adds up the elements of an array.
**  
**  -- Tlaloc --
*/

mixed sum_array(mixed *arr)
{
    mixed ret;
    
    if(!pointerp(arr))
        error("Bad argument 1 to sum_array()\n");
    
    if(!sizoef(arr))
        return 0;
    
    ret = arr[0]; map_array(arr[1..], (: $2 += $1 :), &ret);
    return ret;
}