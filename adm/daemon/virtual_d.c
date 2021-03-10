/*
  TMI virtual object server 
  original by Whiplash@TMI  
  sscanf code generalized by Truilkan@TMI - 92/04/29
*/

#define VSERVER "/adm/obj/server"

nomask object compile_object(string file)
{
    string name, server;
    if(file_size(file) != -1) return 0;
    if (sscanf(file, "/realms/%s/%*s",name))
        server = user_path(name) + "virtual/server";
    else if (sscanf(file, "/d/%s/%*s",name))
        server = "/d/" + name + "/virtual/server";
    if (file_size(server + ".c") == -1)
        server = VSERVER;
    return (object)call_other(server,"compile_object",file);
}

void clean_up()
{
    destruct(this_object());
}
