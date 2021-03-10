string pbar(int num, int numt, int size, int pos, string COL)
{
    int base, remain, var, pri;
    string t;
    if(!intp(num) || !intp(numt)) return "";
    if(!intp(size)) size = 48;
    if(pos != 1 && pos != 2) pos = 1;
    if(!stringp(COL)) COL = "%^B_RED%^";
    if(pos == 1)
    {
        t = "  "+repeat_string("_",size)+"\n";
        base = to_int(((to_float(num) / to_float(numt))) * to_float(size));
        tell_object(find_player("saide"), "base = "+base);
        var = strlen(num+"/"+numt);
        if(base >= size) 
        {
            base = size - var;
            remain = 0;
        }
        else
        {                       
            remain = (size - base);
            base -= var;
            //if(base < 0) base = 0;
            tell_object(find_player("saide"), "base = "+base);
            tell_object(find_player("saide"), "var = "+var);
            tell_object(find_player("saide"), "base+var = "+(base+var)+"");
        }
        if(remain)
        {
            t += "  "+COL+repeat_string(" ",base)+num+"/"+numt+"%^RESET%^"+repeat_string(" ",remain)+"%^RESET%^\n";
            if(base < 0) t += "  "+COL+repeat_string("_",var)+"%^RESET%^"+repeat_string("_",(remain-var))+"%^RESET%^\n";
            else t += "  "+COL+repeat_string("_",(base))+"%^RESET%^"+repeat_string("_",(remain-var))+"%^RESET%^\n";
        }
        else
        {
            pri = base;
            pri -= (base/2);
            t += "  "+COL+repeat_string(" ",(base/2)) + num + "/"+ numt + repeat_string(" ",pri)+"%^RESET%^\n";
            t += "  "+COL+repeat_string("_", (base+var))+"%^RESET%^\n";
        }
    }
    return t;
}