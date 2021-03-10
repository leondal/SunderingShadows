/* support for virtual object servers -- Truilkan@TMI 92/05 */
 
/*  /std/virtual/comiple.c  */
 
int query_prevent_shadow()
{
   return 1;
}
 
object compile_object(string s)
{
   object obj;
   string *tmp;
 
   seteuid(getuid(this_object()));
   obj = new(file_name(this_object()));
   tmp = explode(s,"/");
   obj->virtual_setup(tmp[sizeof(tmp) - 1]);
   return obj;
}
