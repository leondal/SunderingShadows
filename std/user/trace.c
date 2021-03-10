/*
 * trace.c
 * description: tools for developer debugging tools
 * author: taken from the default mudlib.n and modified
 * last modified: 2/5/92
 */

private object find_item(object prev, string str)
{
   object ob;
   string tmp;
   int i;

   if (str == "here")
     return environment(this_object());
   if (str == "^")
     return environment(prev);
   if(sscanf(str, "^%s", tmp) == 1)
     {
	if(!(ob = find_living(tmp)))
	  return 0;
	else
	  return environment(ob);
     }
   if(str == "@")
     return(this_object());
   if (sscanf(str, "@%s", tmp) == 1)
     return find_living(tmp);
   if (sscanf(str, "*%s", tmp) == 1)
     return find_player(tmp);
   if (sscanf(str, "/%s", tmp) == 1) {
      call_other(tmp, "??");	/* Force load */
      return find_object(tmp);
   }
   if (sscanf(str, "$%d", i) == 1) {
      object *u;
      u = users();
      if (i >= sizeof(u) || i < 0)
	return 0;
      return u[i];
   }
   if (prev == 0)
     prev = environment(this_object());
   if (sscanf(str, "\"%s\"", tmp) == 1) {
      ob = first_inventory(prev);
      while(ob && (string)call_other(ob, "query_short") != tmp) {
	 ob = next_inventory(ob);
      }
      return ob;
   }
   if (sscanf(str, "#%d", i) == 1) {
      if (prev == 0)
	return 0;
      ob = first_inventory(prev);
      while(i > 1) {
	 i -= 1;
	 if (ob == 0)
	   return 0;
	 ob = next_inventory(ob);
      }
      return ob;
   }
   if(ob = present(str,prev))
      return ob;

   tmp = (string)this_player()->resolve_path(str);
   if(file_size(tmp+".c") < 0)
      return 0;
   call_other(tmp,"???"); /* Force load */
   return find_object(tmp);
}

object parse_list(string str)
{
   string tmp, rest;
   object prev;

   prev = environment(this_object());
   while(prev && str) {
      if (sscanf(str, "%s:%s", tmp, rest) == 2) {
	 prev = find_item(prev, tmp);
	 str = rest;
	 continue;
      }
      prev = find_item(prev, str);
      break;
   }
   return prev;
}


get_act_ob(string str)
{
    object ob;
    if(!str)
        return this_player();

    if(ob = parse_list(str))
        return ob;
    else
        return 0;
}

get_e_act_ob(string str)
{
    object ob;

    if(!str)
        return this_player();

    ob = parse_list(str);
    if(!ob)
        return 0;
    if(ob->query_name())
        if(find_living(lower_case(ob->query_name())))
            return environment(ob);
    return ob;
}

mixed *parse_args(string str)
{
   string tmp1, tmp2;
   string strn;
   int i,num;
   object ob;

   if(!str || str == "")
   {
      return ({});
   }

   switch(str[0])
   {
      case '#':
         if(sscanf(str,"#%d#%s",num,str) != 2)
         {
            write("Error in arguments format!\n");
            return ({});
         }
         return ({ num }) + parse_args(str);
         break;
      case '"':
         if(sscanf(str,"\"%s\"%s",strn,str) != 2)
         {
            write("Error in arguments format!\n");
            return ({});
         }
         return ({ strn }) + parse_args(str);
         break;
      case '(':
         if(sscanf(str,"(%s)%s",strn,str) != 2)
         {
            write("Error in arguments format!\n");
            return ({});
         }
         if(!(ob = parse_list(strn)))
         {
            write("Object: "+strn+" not found!\n");
            return ({});
         }
         return ({ ob }) + parse_args(str);
         break;
      case '{':
         if(sscanf(str,"{%s}%s",strn,str) != 2)
         {
            write("Error in arguments format!\n");
            return ({});
         }
         return ({ parse_args(strn) }) + parse_args(str);
         break;
   }
}
