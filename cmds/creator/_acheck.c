//      a tool for the balancing and checking of armour
// 	modified for use in ShadowGate by Melnmarn

#include <std.h>
#include <abalance.h>

inherit DAEMON;
nosave string *magical, *limbs, *id, *dir, read_msg, home_path;
nosave string path,name,rname,short,long,type,wear_string,unwear_string;
nosave int ac, value, weight, is_armour,enchanted;
int error;

mixed *query_names(){ return(keys(ARMOR_MISC)); }
int check_armour(object ob)
{
    int i;

    error = 0;

    if (member_array("std/armour.c", deep_inherit_list(ob)) == -1)
	if (path != "/std/armour") {
	     write_file(home_path,"Warning: " + path +
		" is not a subclass of /std/armour.\n");
	    error = 1;
	}

    is_armour = (int)ob->is_armour();
    if (!intp(is_armour)) {
	write_file(home_path,"Warning: is_armour() did not return an int.\n");
	error = 1;
    } else
	if (!is_armour) {
	    write_file(home_path,"Warning: is_armour() did not return true.\n");
	    error = 1;
	}

    type = (string)ob->query_type();
    if (!stringp(type)) {
	write_file(home_path,"Warning: query_type() did not return a string.\n");
	error = 1;
    }

    rname = (string)ob->query_name();
    if (!stringp(rname)) {
	write_file(home_path,"Warning: query_name() did not return a string.\n");
	error = 1;
    }
    if(member_array(rname,keys(ARMOR_MISC)) == -1)
      if(type != "clothing"){
	write_file(home_path,"Warning: query_name() did not return a valid name.\n");
	error = 1;
      } else
	name = "clothing";
    else
	name = rname;

    if ((type != ARMOR_MISC[name][3]) && ( type != "clothing" )) {
	    write_file(home_path,"Warning: query_type() returned unknown armour " +
		"type: " + type + ".\n");
	    error = 1;
     }

    id = (string *)ob->query_id();
    if (!pointerp(id)) {
	write_file(home_path,"Warning: query_id() did not return an array.\n");
	error = 1;
    } else
	for (i = 0; i < sizeof(id); i++)
	    if (!stringp(id[i])) {
		write_file(home_path,"Warning: query_id() array member " + i +
		    " is not a string.\n");
		error = 1;
	    }

    short = (string)ob->query_short();
    if (!stringp(short)) {
	write_file(home_path,"Warning: query_short() did not return a string.\n");
	error = 1;
    }

    long = (string)ob->query_long();
    if (!stringp(long)) {
	write_file(home_path,"Warning: query_long() did not return a string.\n");
	error = 1;
    }
    enchanted = (int)ob->query_property("enchantment");
    ac = (int)ob->query_ac();
    if (!intp(ac)) {
	write_file(home_path,"Warning: query_ac() did not return an int.\n");
	error = 1;
    } else
	if ((ac - enchanted) != ARMOR_MISC[name][2]) {
	    write_file(home_path,"Warning: query_ac() is not balanced.\n");
	    error = 1;
	}

    value = (int)ob->query_value();
    if (!intp(value)) {
	write_file(home_path,"Warning: query_value() did not return an int.\n");
	error = 1;
    }
    weight = (int)ob->query_weight();
    if (!intp(weight)) {
	write_file(home_path,"Warning: query_weight() did not return an int.\n");
	error = 1;
    } else
	if ((weight != ARMOR_MISC[name][1]) && (type != "clothing")) {
	    write_file(home_path,"Warning: query_weight() is not balanced.\n");
	    error = 1;
	}
    limbs = (string *)ob->query_limbs();
    if (!pointerp(limbs)) {
	write_file(home_path,"Warning: query_limbs() did not return an array.\n");
	error = 1;
    } else {
	for (i = 0; i < sizeof(limbs); i++){
	    if(!stringp(limbs[i])) {
		write_file(home_path,"Warning: query_limbs() array member " + i +
		    " is not a string.....\n");
		error = 1;
	    }
	    else if(type == "clothing");
	    else if(strsrch(limbs[i],"hand") != -1){
	    	if("hand" != ARMOR_MISC[name][4]){
			write_file(home_path,"Warning: query_limbs() array member " + i +
		    	" is not a valid limb type for this armor.\n");
			error = 1;
	        }
            }
 	    else if(limbs[i] != ARMOR_MISC[name][4]){
			write_file(home_path,"Warning: query_limbs() array member " + i +
		    	" is not a valid limb type for this armor...\n");
			error = 1;
    	    }
	}
    }
    wear_string = (string)ob->query_wear();
    if (functionp(wear_string))
      if (!stringp(function_exists(wear_string[1], ob))) {
          write_file(home_path,"Warning: function \"" + wear_string[1] + "\" is called in set_wear, but does not exist.\n");
          error = 1;
      }

    unwear_string = (string)ob->query_unwear();
    if (functionp(unwear_string))
      if (!stringp(function_exists(unwear_string[1], ob))) {
          write_file(home_path,"Warning: function \"" + unwear_string[1] + "\" is called in set_remove, but does not exist.\n");
          error = 1;
      }
    read_msg = ob->query("read");
    magical = (string *)ob->query_property("magic item");
   return !error;


}

void print_armour(object ob)
{
    int i;

    string melnmarn = "";
    melnmarn += "%^GREEN%^Short:%^BOLD%^%^BLACK%^ ------------ %^RESET%^%^CYAN%^" + short + "\n";
    melnmarn += "%^GREEN%^Long: %^BOLD%^%^BLACK%^------------- %^RESET%^%^CYAN%^" + long + "\n";
    melnmarn += "%^GREEN%^User ID: %^BOLD%^%^BLACK%^---------- %^RESET%^%^CYAN%^" + getuid(ob) + "\n";
    melnmarn += "%^GREEN%^EUID: %^BOLD%^%^BLACK%^------------- %^RESET%^%^CYAN%^" + geteuid(ob) + "\n";
    melnmarn += "%^GREEN%^Name: %^BOLD%^%^BLACK%^------------- %^RESET%^%^CYAN%^" + rname + "\n";
    melnmarn += "%^GREEN%^ID's: %^BOLD%^%^BLACK%^------------- %^RESET%^%^CYAN%^";
    for (i = 0; i < sizeof(id); i++)
	melnmarn += "%^YELLOW%^\"%^RESET%^%^CYAN%^" + id[i] + "%^YELLOW%^\" ";
    melnmarn += "%^RESET%^\n";
    melnmarn += "%^GREEN%^Type: %^BOLD%^%^BLACK%^------------- %^RESET%^%^CYAN%^" + type + "\n";
    melnmarn += "%^GREEN%^Armour Class: %^BOLD%^%^BLACK%^----- %^RESET%^%^CYAN%^" + (10 - ac) + "\n";
    if(enchanted)
    	melnmarn += "%^GREEN%^Enchantment: %^BOLD%^%^BLACK%^------ %^RESET%^%^CYAN%^+" + enchanted + "\n";

    melnmarn += "%^GREEN%^Value: %^BOLD%^%^BLACK%^------------ %^RESET%^%^CYAN%^" + value + ((int)ob->query_destroy() ? "*" : "") + "\n";
    melnmarn += "%^GREEN%^Weight: %^BOLD%^%^BLACK%^----------- %^RESET%^%^CYAN%^" + weight + " pounds.\n";
    melnmarn += "%^GREEN%^Limb: %^BOLD%^%^BLACK%^------------- %^RESET%^%^CYAN%^";
    for (i = 0; i < sizeof(limbs); i++)
	melnmarn += "\"" + limbs[i] + "\" ";
    melnmarn += "\n";

   if (stringp(wear_string))
    melnmarn += "%^GREEN%^Wear String: %^BOLD%^%^BLACK%^------ %^RESET%^%^CYAN%^" + wear_string + "\n";
   if(functionp(wear_string))
    melnmarn += "%^GREEN%^Wear Func: %^BOLD%^%^BLACK%^-------- %^RESET%^%^CYAN%^" + wear_string[1] + "()\n";

   if (stringp(unwear_string))
    melnmarn += "%^GREEN%^Remove String: %^BOLD%^%^BLACK%^---- %^RESET%^%^CYAN%^" + unwear_string + "\n";
   if(functionp(unwear_string))
    melnmarn += "%^GREEN%^Remove Func: %^BOLD%^%^BLACK%^------ %^RESET%^%^CYAN%^" + unwear_string[1] + "()\n";
   if(stringp(read_msg))
    melnmarn += "%^GREEN%^Read String: %^BOLD%^%^BLACK%^------ %^RESET%^%^CYAN%^" + read_msg + "\n";
   if(functionp(read_msg))
    melnmarn += "%^GREEN%^Read Func: %^BOLD%^%^BLACK%^-------- %^RESET%^%^CYAN%^" + read_msg + "\n";
   if(pointerp(magical)){
    melnmarn += "%^GREEN%^Magic: %^BOLD%^%^BLACK%^------------ %^RESET%^%^CYAN%^";
    for (i = 0; i < sizeof(magical); i++)
	melnmarn += "%^YELLOW%^\"%^RESET%^%^CYAN%^" + magical[i] + "%^YELLOW%^\" ";
    melnmarn += "%^RESET%^\n";
   }

    if(!error){
    	write_file(home_path,"PASSED\n");
    	melnmarn += "%^GREEN%^Status: %^BOLD%^%^BLACK%^----------- %^RESET%^%^CYAN%^Passed basic *Balance* check.";
    }
    else{
    	melnmarn += "%^GREEN%^Status: %^BOLD%^%^BLACK%^----------- %^RESET%^%^RED%^Failed basic *Balance* check.";
    }

    write(melnmarn);
}

int cmd_acheck(string armour)
{
    int inc;
    object ob;
    seteuid("Root");
    home_path = TP->get_path()+"/acheck.log";
    if(file_size(home_path) > 0) rm(home_path);
    if(!stringp(armour)) {
	dir = get_dir(TP->get_path()+"/*.c");
    	for(inc = 0;inc < sizeof(dir);inc++){
	    dir[inc] = replace_string(dir[inc],".c","");
	    ob = new(TP->get_path()+"/"+dir[inc]);
    	    write_file(home_path,replace_string(arrange_string(capitalize(dir[inc]),10)," ","-",2,10)+": ");
    	    check_armour(ob);
    	    if(!error) {
		write_file(home_path,"PASSED\n");
		write("%^GREEN%^Checking: %^BOLD%^%^BLACK%^--------- %^MAGENTA%^" + arrange_string(capitalize(dir[inc]),20)+" %^GREEN%^Passed.");
	    }
	    else
		write("%^GREEN%^Checking: %^BOLD%^%^BLACK%^--------- %^MAGENTA%^" + arrange_string(capitalize(dir[inc]),20)+" %^RED%^Failed.");
	}
	return 1;
    }
    if(!stringp(armour)) {
	notify_fail("usage: " + query_verb() + " <armour-id>\n");
	return 0;
    }

    ob = present(armour, this_player());
    if (!objectp(ob)) {
      	ob = present(armour, environment(TP));
    }
    if (!objectp(ob)) {
	    catch(ob = new(TP->get_path() + "/" + armour));
    }
    if (!objectp(ob)) {
	notify_fail(query_verb() + ": \"" + armour + "\" not present.\n");
	return 0;
    }

    path = base_name(ob);
    write("%^GREEN%^Checking: %^BOLD%^%^BLACK%^--------- %^MAGENTA%^" + capitalize(armour));
    write("%^GREEN%^Path: %^BOLD%^%^BLACK%^------------- %^RESET%^%^CYAN%^\"" + path + "\"");
    write_file(home_path,replace_string(arrange_string(capitalize(armour),10)," ","-",2,10)+": ");
    check_armour(ob);
    print_armour(ob);
    return 1;
}

int help(){
  write( @EndText
Syntax: acheck <name>
Effect: Balance command to check armor.
        Checks the armor called <name> in your inventory for weight, wc, etc
See doc: /doc/QC/check.doc
See also: rcheck, wcheck
EndText
  );
  return 1;
}
