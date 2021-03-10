// re-written for ShadowGate by Melnmarn
/* original code by Cygnus@Nightmare */


#include <wbalance.h>
#include <std.h>

inherit DAEMON;

string path, home_dir;
int is_weapon;
string short;
string long;
string name;
string *id;
string type;
int sdamage, ldamage, weight;
mixed wield_string;
mixed unwield_string;
mixed hit_string;
object wield_func_ob, hit_func_ob;
int decay_rate,size;
mixed read_msg;
string value;


int check_weapon(object ob)
{
    int error;
    int i;

    error = 0;

    if (member_array("std/weapon.c", deep_inherit_list(ob)) == -1)
	if (path != "/std/weapon") {
	    write_file(home_dir,"Warning: " + file_name(ob) + " is not a subclass of /std/weapon.\n");
	    error = 1;
	}

    is_weapon = (int)ob->is_weapon();
    if (!intp(is_weapon)) {
	write_file(home_dir,"Warning: is_weapon() did not return an int.\n");
	error = 1;
    } else
	if (!is_weapon) {
	    write_file(home_dir,"Warning: is_weapon() did not return true.\n");
	    error = 1;
	}

    name = (string)ob->query_name();
    if (!stringp(name)) {
		write_file(home_dir,"Warning query_name() did not return a valid name.\n");
	error = 1;
    } else {
	if(!WEAPONS_MISC[name]){
		write_file(home_dir,"Warning query_name() did not return a valid name.  '"+name+"' \n");
		return 0;
    	}
    }

    id = (string *)ob->query_id();
    if (!pointerp(id)) {
	write_file(home_dir,"Warning: query_id() did not return an array.\n");
	error = 1;
    } else
	for (i = 0; i < sizeof(id); i++)
	    if (!stringp(id[i])) {
		write_file(home_dir,"Warning: query_id() array member " + i +
		    " is not a string.\n");
		error = 1;
	    }

    short = (string)ob->query_short();
    if (!stringp(short)) {
	write_file(home_dir,"Warning: query_short() did not return a string.\n");
	error = 1;
    }

    long = (string)ob->query_long();
    if (!stringp(long)) {
	write_file(home_dir,"Warning: query_long() did not return a string.\n");
	error = 1;
    }
    
    type = (string)ob->query_type();
    if (!stringp(type)) {
	write_file(home_dir,"Warning: query_type() did not return a string.\n");
	error = 1;
    } else
	if(type != WEAPONS_MISC[name][2]) {
	    write_file(home_dir,"Warning: query_type() returned unknown weapon " +
		"type: " + type + ".\n");
	    error = 1;
	}

    weight = (int)ob->query_weight();
    if (!intp(weight)) {
	write_file(home_dir,"Warning: query_weight() did not return an int.\n");
	error = 1;
    } else
	if (weight != WEAPONS_MISC[name][0]) {
	    write_file(home_dir,"Warning: query_weight() is not balanced.\n");
	    error = 1;
	}

    size = (int)ob->query_size();
    if (!intp(size)) {
	write_file(home_dir,"Warning: query_size() did not return an int.\n");
	error = 1;
    } else
	if (size != WEAPONS_MISC[name][1]) {
	    write_file(home_dir,"Warning: query_size() is not balanced.\n");
	    error = 1;
	}

    sdamage = (int)ob->query_wc();
    if (!intp(sdamage)) {
	write_file(home_dir,"Warning: query_wc() did not return an int.\n");
	error = 1;
    } else
	if ( sdamage!= WEAPONS_MISC[name][3]) {
	    write_file(home_dir,"Warning: query_wc() is not balanced.\n");
	    error = 1;
	}

    ldamage = (int)ob->query_large_wc();
    if (!intp(ldamage)) {
	write_file(home_dir,"Warning: query_large_wc() did not return an int.\n");
	error = 1;
    } else
	if (ldamage != WEAPONS_MISC[name][4]) {
	    write_file(home_dir,"Warning: query_large_wc() is not balanced.\n");
	    error = 1;
	}

    decay_rate = (int)ob->query_decay_rate();
    if (!intp(decay_rate)) {
	write_file(home_dir,"Warning: query_decay_rate() did not return an int.\n");
	error = 1;
    }

    wield_string = (string)ob->query_wield();
    if (functionp(wield_string))
	if (!stringp(function_exists(wield_string[1], ob))) {
	    write_file(home_dir,"Warning: function \"" + wield_string[1] + "\" is called in set_wield, but does not exist.");
	    error = 1;
	}

    unwield_string = (string)ob->query_wield();
    if (functionp(unwield_string))
	if (!stringp(function_exists(unwield_string[1], ob))) {
	    write_file(home_dir,"Warning: function \"" + unwield_string[1] + "\" is called in set_unwield, but does not exist.");
	    error = 1;
	}

    hit_string = (string)ob->query_hit();
    if (functionp(hit_string))
	if (!stringp(function_exists(hit_string[1], ob))) {
	    write_file(home_dir,"Warning: function \"" + hit_string[1] + "\" is called in set_hit, but does not exist.");
	    error = 1;
	}
    value = ob->query_value();
    if(!intp(value)) {
	    write_file(home_dir,"Warning: set_value() does not return an int.");
	    error = 1;
    }

    read_msg = ob->query("read");

    if(!error)
	write_file(home_dir,"PASSED\n");

    return !error;
}

void
print_weapon(object ob)
{
    int i;
    string melnmarn = "";

    melnmarn += "%^GREEN%^Path%^BOLD%^%^BLACK%^: -----------%^RESET%^%^CYAN%^ " + path + "\n";
    melnmarn += "%^GREEN%^User ID%^BOLD%^%^BLACK%^: --------%^RESET%^%^CYAN%^ " + getuid(ob) + "\n";
    melnmarn += "%^GREEN%^EUID%^BOLD%^%^BLACK%^: -----------%^RESET%^%^CYAN%^ " + geteuid(ob) + "\n";
    melnmarn += "%^GREEN%^Name%^BOLD%^%^BLACK%^: -----------%^RESET%^%^CYAN%^ " + name + "\n";
    melnmarn +=("%^GREEN%^IDs%^BOLD%^%^BLACK%^: ------------");
    for (i = 0; i < sizeof(id); i++)
	melnmarn += "%^YELLOW%^ \"%^RESET%^%^CYAN%^" + id[i] + "%^YELLOW%^\"";
    melnmarn += "\n%^RESET%^";
    melnmarn += "%^GREEN%^Type%^BOLD%^%^BLACK%^: -----------%^RESET%^%^CYAN%^ " + type + "\n";
    melnmarn += "%^GREEN%^Size%^BOLD%^%^BLACK%^: -----------%^RESET%^%^CYAN%^ ";
	switch(size){
		case 1: melnmarn += "Small\n";break;
		case 2: melnmarn += "Medium\n";break;
		default: melnmarn += "Large\n";break;
	}
    melnmarn += "%^GREEN%^Weight%^BOLD%^%^BLACK%^: ---------%^RESET%^%^CYAN%^ " + weight + " pounds.\n";
    melnmarn += "%^GREEN%^Value%^BOLD%^%^BLACK%^: ----------%^RESET%^%^CYAN%^ " + value + " " + (string)ob->query_cointype() + "\n";
    melnmarn += "%^GREEN%^Short%^BOLD%^%^BLACK%^: ----------%^RESET%^%^CYAN%^ " + short + "\n";
    melnmarn += "%^GREEN%^Long%^BOLD%^%^BLACK%^: -----------%^RESET%^%^CYAN%^ " + long + "\n";
    melnmarn += "%^GREEN%^Damage(s)%^BOLD%^%^BLACK%^: ------%^RESET%^%^CYAN%^ " + sdamage + " Maximum.\n";
    melnmarn += "%^GREEN%^Damage(l)%^BOLD%^%^BLACK%^: ------%^RESET%^%^CYAN%^ " + ldamage + " Maximum.\n";
    melnmarn += "%^GREEN%^Decay Rate%^BOLD%^%^BLACK%^: -----%^RESET%^%^CYAN%^ " + decay_rate + "\n";

    if (stringp(wield_string))
    melnmarn += "%^GREEN%^Wield String%^BOLD%^%^BLACK%^: ---%^RESET%^%^CYAN%^ " + wield_string + "\n";
    if(functionp(wield_string)) 
    melnmarn += "%^GREEN%^Wield func%^BOLD%^%^BLACK%^: -----%^RESET%^%^CYAN%^ " + wield_string[1] + "()\n";

    if (stringp(unwield_string))
    melnmarn += "%^GREEN%^Unwield String%^BOLD%^%^BLACK%^: -%^RESET%^%^CYAN%^ " + unwield_string + "\n";
    if(functionp(unwield_string)) 
    melnmarn += "%^GREEN%^Unwield func%^BOLD%^%^BLACK%^: ---%^RESET%^%^CYAN%^ " + unwield_string[1] + "()\n";

    if (stringp(hit_string))
    melnmarn += "%^GREEN%^Hit String%^BOLD%^%^BLACK%^: -----%^RESET%^%^CYAN%^ " + hit_string + "\n";
    if(functionp(hit_string)) 
    melnmarn += "%^GREEN%^Hit func%^BOLD%^%^BLACK%^: -------%^RESET%^%^CYAN%^ " + unwield_string[1] + "()\n";

    if (stringp(read_msg))
    melnmarn += "%^GREEN%^Read String%^BOLD%^%^BLACK%^: ----%^RESET%^%^CYAN%^ " + read_msg + "\n";
    if(functionp(read_msg)) 
    melnmarn += "%^GREEN%^Read func%^BOLD%^%^BLACK%^: ------%^RESET%^%^CYAN%^ " + read_msg[1] + "()\n";
    melnmarn += "%^GREEN%^Status%^BOLD%^%^BLACK%^: ---------%^RESET%^%^CYAN%^ Passed basic *Balance* check.";
    write(melnmarn);
	
}

int cmd_wcheck(string weapon)
{
    object ob;
    string *dir;
    int inc;
    seteuid("Root");
    home_dir = TP->get_path()+"/wcheck.log";
    if(!stringp(weapon)) {
	if(file_size(home_dir) > 0) rm(home_dir);
        dir = get_dir(TP->get_path()+"/*.c");
        for(inc = 0;inc < sizeof(dir);inc++){
            dir[inc] = replace_string(dir[inc],".c","");
            ob = new(TP->get_path()+"/"+dir[inc]);
    	write("%^GREEN%^Weapon Check for%^BOLD%^%^BLACK%^: %^RESET%^%^YELLOW%^" + capitalize(dir[inc]));
	    write_file(home_dir,arrange_string(capitalize(dir[inc])+":",15));
            check_weapon(ob);
        }
	return 1;
    }
    if (!stringp(weapon)) {
	notify_fail("usage: " + query_verb() + " <weapon-id|weapon-filename>\n");
	return 0;
    }

    ob = present(weapon, this_player());
    if (!objectp(ob)) {
      	ob = present(weapon, environment(TP));
    }
    if (!objectp(ob)) {
	    catch(ob = new(TP->get_path() + "/" + weapon));
    }
    if (!objectp(ob)) {
	notify_fail(query_verb() + ": \"" + weapon + "\" not present.\n");
	return 0;
    }

    path = base_name(ob);

    write("%^GREEN%^Weapon Check for%^BOLD%^%^BLACK%^: %^RESET%^%^YELLOW%^" + capitalize(weapon));
    if (check_weapon(ob))
	print_weapon(ob);

    return 1;
}

int help()
{
  write( @MelnMarn
Syntax: wcheck <name | filename>

Effect: Balance command to check weapons.
        Checks the weapon called <name> for weight, wc, etc
	Looks in your inventory, then your environent, then 
	your current working directory. 
	
	Right way:
		IE: 'wcheck longsword' finds object or filename.
	Wrong way:
		IE: 'wcheck /weapons/longsword.c' will *NOT* work.


See doc: /doc/help/creator/weapons and /doc/build/weapons/tutorial
See also: acheck, rcheck
MelnMarn
  );
return 1;
}
