// A cool file from Portals.


string *wild_card(string str) {
   string work;
   string *tmp;
   string *pf;
   int i;

   work = resolv_path((string)this_object()->get_path(), str);
   if(work == "/") return ({ "/" }); /* Special case! Yuck! */

   pf = path_file(work);
   if (pf[0] == "/") pf[0] = ""; /* yuck! yet another special case! */
   tmp = get_dir(work);
   if(!tmp) tmp = ({});
   tmp -= ({ "." });
   tmp -= ({ ".." });
   if(!str || str[0] != '.') {
      tmp = filter_array(tmp, "remove_dots", this_object());
   }

   for(i = 0; i < sizeof(tmp); i++)
   {
      if(file_size(pf[0]+"/"+pf[1]) == -2)
         tmp[i] = pf[0];
      else
         tmp[i] = pf[0] + "/" + tmp[i];
   }
   return tmp;
}

int remove_dots(string tmp)
{
   if(tmp[0] == '.')
      return 0;
   return 1;
}
