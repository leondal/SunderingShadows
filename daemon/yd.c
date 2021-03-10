#include <security.h>
#include <move.h>

void assure_save_dir_exists(string file) {
    string *elems;
    string path;
    int i;

    elems = explode(file, "/");
    path = "";
    for (i=0; i < sizeof(elems) - 1; i++) {
                path += "/" + elems[i];
                if (file_size(path) == -1) {
                write("Make dir " + path + "\n");
                mkdir(path);
                }
    }
}

void save_inventory(object ob)
{
  object *inv;
  string fname;
  int x,j;
  string *oldfiles;

  inv = all_inventory(ob);
  assure_save_dir_exists("/inv/"+ob->query_name()+"/ob");
  oldfiles = get_dir("/inv/"+ob->query_name()+"/");
  seteuid(UID_ROOT);
  rm("/inv/"+ob->query_name()+".log");
  for(x=0;x<sizeof(oldfiles);x++){
        j = rm("/inv/"+ob->query_name()+"/"+oldfiles[x]);
  }
  seteuid(getuid());
  j = 0;

//  write("Saving inventory.");
  for(x = 0; x < sizeof(inv); x++)
   {
//     tell_object(ob,"Saving Object #"+x+"\n");
     fname = "/inv/"+ob->query_name()+"/ob"+x;
//write("file name = "+fname);
		 write_file("/inv/"+ob->query_name()+".log", 
		            file_name(ob)+" ---> "+ob->query_short()
		           );
     j=inv[x]->save_me(fname);
   }

}

void load_inventory(object ob)
{
// move all cloned objects to ob
  string fname,fn,s1,s2,*files;
  int i,j,x,fsize,oldsize,z;
  object tmp;
  object *old;


  x = 0;
  old = all_inventory(ob);
  oldsize = sizeof(old);
//  Remove anything in the inventory that might be there beforehand
//  so there is no possible duplication of items.  -- Thorn
  for(z=0;z<oldsize;z++) {
        if(!destruct(old[z])) old[z]->remove();
  }

  seteuid(getuid());
  fsize = sizeof(files = get_dir("/inv/"+ob->query_name()+"/ob*"));
  write("Loading Inventory");
  for(x = 0; x < (fsize) ; x++)
   {
//    write("Loading Object #"+x);
    fname = "/inv/"+ob->query_name()+"/"+files[x];
//write("file name = "+files[x]);
    if(file_exists(fname)) {
      fn = read_file(fname,1,1);
      if(!stringp(fn)) continue;
      sscanf(fn,"#%s.c",s1);
      s1 = "/"+s1;
      if(catch(tmp = new(s1)))
        tell_object(ob,"Error: File "+s1+" not found");
      sscanf(fname,"%s.o",fn);
      j = catch(i = tmp->restore_me(fn));
      if(j) {
        tell_object(ob,"There is a problem with one of your items.
Ignoring.");
        rm(fname);
      }
      if(!j){
 //    tell_object(ob,"loading "+fname);
        if(tmp->move(ob) != MOVE_OK){
                tmp->move(environment(ob));
                tell_object(ob,"You dropped something");
        }
        tmp->restore_me(fn+".o");
        rm(fname);
      }
    }
  }
}

//  Checks Circumstances that might cause multiple reloads of
//  player inventories.  VERY IMPORTANT thing to avoid.
//  -- Thorn 960117

int check_circumstances() {

        return 1;
}
