/*
  generic virtual object server
 
  by Truilkan@TMI - 92/05
 
  version 0.8
*/
int query_prevent_shadow()
{
   return 1;
}
 
object compile_object(string file)
{
    string name, server, tmp, args;
    object obj;
    if (sscanf(file,"%s.%s",args,tmp) != 2)
    {
        log_file("virtual_rooms", "Invalid args and tmp in compile_object in server.c");
        return 0;
    }
    if (sscanf(file,"/realms/%s/%*s",name))
    {        
        server = user_path(name) + "virtual/" + tmp + "_server";
    }
    else if (sscanf(file,"/d/%s/%*s",name))
    {    
        server = "/d/" + name + "/virtual/" + tmp + "_server";
    }
    if (file_size(server + ".c") != -1) 
    {
        return (object)call_other(server,"compile_object",args);
    }
    log_file("virtual_rooms", "virtual server "+server+".c does not exist.");
    server = "/daemon/virtual/" + tmp + "_server";
    tell_object(find_player("saide"), "server = "+server);
    if (file_size(server + ".c") != -1) 
    {
        return (object)call_other(server,"compile_object",args);
    }
    log_file("virtual_rooms", "virtual server "+server+".c does not exist.");
    return 0;
}
 
void clean_up()
{
   destruct(this_object());
}
 
void create()
{
   seteuid(getuid(this_object()));
}
