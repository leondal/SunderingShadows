//
#include <std.h>
#include <move.h>
#include <dirs.h>


inherit DAEMON;

void load_inventory(string who);
private string save_file_name(string name);

string posxxx; 

int cmd_profile(string strg) 
{
    string *classes, who, describe,short, class1, class2, class3, race, gender;
    int hp, level1,level2,level3,i,j, fsize, str,inte,con,dex,cha,wis;
    object *inven;
    string *files;

   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if (!strg) {
	return notify_fail("Syntax: profile <save|change> <virtual name>\n");

    }
    if (sscanf(strg,"%s %s",strg, who) != 2) {

	return notify_fail("Syntax: profile <save|change> <virtual name>\n");
    }

    if (strg != "save" && strg != "change") {

	return notify_fail("Syntax: profile <save|change> <virtual name>\n");
    }
    if (strg == "change") {
	if (!file_exists("/avatar/"+TPQTN+"/"+who+".o")) {
	    return notify_fail("You have not established that persona.\n");
	}
//      TP->set_vis_name(who);
	TP->set_id(({"player",who}));
///	TP->set_disguised(1);
	TP->restore_me("/avatar/"+TPQTN+"/"+who);
	inven = all_inventory(TP);
	j = sizeof(inven);
	for (i=0;i<j;i++) {
	    if (objectp(inven[i])) {
		destall(inven[i]);
	    }
	}

	TP->new_body();   
	load_inventory(who);


	TP->reinit_path();
	tell_object(TP,"%^BOLD%^You slowly feel yourself change into a whole new person.");
	TP->update_channels();
    } else {
	who = lower_case(who);
	if ((who == (string)TPQN) || (file_exists("/avatar/"+TPQN+"/"+who+".o") ) ) {
	 write ("Overwriting persona");;
	} else { 
	  if (user_exists(who)) {
	    return notify_fail("That player exists, Sorry.\n");
	  }
	}
	files = get_dir("/avatar/"+TP->query_name()+"/"+who+"dir/*.o");
	j = sizeof(files);
	for (i=0;i<j;i++) {
	    rm("/avatar/"+TP->query_name()+"/"+who+"dir/"+files[i]);
	}
	rmdir("/avatar/"+TP->query_true_name()+"/"+who);
	rm("/avatar/"+TP->query_name()+"/"+who+".o");
    TP->set("persona", 1);
	TP->save_me("/avatar/"+TP->query_name()+"/"+who);
    TP->delete("persona");
	mkdir("/avatar/"+TP->query_name()+"/"+who+"dir");
    
	inven = all_inventory(TP);
	j = sizeof(inven);
	mkdir("/inv/"+who);
	for (i=0;i<j;i++) {
	    if (objectp(inven[i])) {
		inven[i]->save_me("/avatar/"+TP->query_name()+"/"+who+"dir/ob"+i);
		inven[i]->save_me("/inv/"+who+"/ob"+i);
	    }
	}
	tell_object(TP,"%^BOLD%^Your person is saved for future use.");


	seteuid("UserSave");
	"/daemon/yuck_d"->save_inventory(this_player());
	TP->compute_autoload_array(); /* Tru - 92/02/11 */
    cp("/avatar/"+TP->query_name()+"/"+who+".o",save_file_name(who)+".o");
    }

return 1;
}

private string save_file_name(string name) {
    return sprintf("%s/%s/%s", DIR_USERS, name[0..0], name);
}

void load_inventory(string who) 
{
    string *classes,file;
    int i,j, fsize;
    object *inven, tmp;
    string fname,fn,s1,*files;

    seteuid(getuid());
    fsize = sizeof(files = get_dir("/avatar/"+TP->query_name()+"/"+who+"dir/ob*"));

    write("Loading Inventory");

    for (i = 0; i < (fsize) ; i++) 
    {
	//	 write("Loading Object #"+i);
	    fname = "/avatar/"+TP->query_name()+"/"+who+"dir/"+files[i];
	//	 write("file name = "+files[i]);
	    if (file_exists(fname)) 
        {
		    fn = read_file(fname,1,1);
            if(!stringp(fn)) { continue; }
		    
            sscanf(fn,"#%s.c",s1);
		    s1 = "/"+s1;
		    
            if(catch(tmp = new(s1))) 
            {
			    tell_object(TP,"Error: File "+s1+" not found");
			    continue;
		    }
		    
            sscanf(fname,"%s.o",fn);
		    
            j = catch( tmp->restore_me(fn));
		    
            if (j) 
            {
			    tell_object(TP,"There is a problem with one of your items. Ignoring.");
			    //          rm(fname);
		    }

		    if(!j) 
            {
			    tell_object(TP,"loading "+fname);
			    if (tmp->move(TP) != MOVE_OK) 
                {
			        tmp->move(environment(TP));
			        tell_object(TP,"You dropped something");
			    }
                if(objectp(tmp)) { tmp->restore_me(fn+".o"); }
                else { tell_object(TP,"Error restoring "+s1+""); }
		    }
        }
    }
}


int help() 
{
    write("Syntax: profile <save|change> <virtual name>\n\n"
	    "  Allows you to change your persona or save your current settings.");
	return 1;
}
