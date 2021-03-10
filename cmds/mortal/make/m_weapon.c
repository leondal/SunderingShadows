#include <std.h>
#include "/cmds/creator/make/m_weapon.h"
#include <security.h>
#include "/cmds/creator/make/makeobj.h"

//inherit DAEMON;
// Function prototypes

// int obs(string file, string name, object ob);
// int exit(string file, string name, object ob);
int wdone(string file, string name, object ob);
    string weapon_type;

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int start_up( string file){
    object ob;
    string name;
 
    ob=this_player();
    name=ob->query_name();
    seteuid(UID_CRESAVE);

    write_file(file, "// This file was created by "+ob->query_cap_name()+"\n");
    write_file(file, "// For Circle "+ctime(time())+"\n");
    write_file(file, "// Please do not remove this header.\n");
    write_file(file, "// Report problems of this code to Creator or Tinks.\n\n");
    write_file(file, "#include <std.h>\n");
    write_file(file, "\ninherit WEAPON;\n");
    write_file(file, "\nvoid create()  {\n");
    write_file(file, "\t::create();\n");
    write("Creating: " + file + "\n");

    tell_object(ob, "\nObject id [aliases for weapon seperated by \"/\" ]: ");
    tell_object(ob, "\tEx: sword/bastard sword/bastard/bastardsword " );
    input_to("iddd", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int iddd( string arg, string file, string name, object ob )  {

    string ids;

    if ( (arg == " ")||(arg == "")||(!arg) ){
        tell_object(ob, "\nObject id [aliases for weapon seperated by \"/\" ]: ");
        tell_object(ob, "\tEx: sword/bastard sword/bastard/bastardsword " );
        input_to("iddd", file, name, ob);
        return 1;
    }

    ids = implode(explode(arg, "/"), "\", \"");

    write_file(file, "\tset_id( ({ \"" + lower_case(ids) + "\" }) );\n");
        
    tell_object(ob, "\nEnter weapon name [single word, no caps]: ");
    input_to("wname", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wname( string arg, string file, string name, object ob )  {

    if ( (arg == " ") || (arg == "") || (!arg) ){
        tell_object(ob, "\nEnter weapon name [single word, no caps ]: ");
        input_to("wname", file, name, ob);
        return 1;
    }

    if (strsrch(arg, " ") > -1)  {
        tell_object(ob, "\nWeapon name must be a single word]: ");
        input_to("wname", file, name, ob);
        return 1;
    }
  
    write_file(file, "\tset_name(\""+lower_case(arg)+"\");\n");

    tell_object(ob, "\nShort description: ");
    tell_object(ob, "\tThis is how it will be seen in the player's inventory ");
    input_to("wshort", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wshort( string arg, string file, string name, object ob ){

    if ( (arg == " ") || (arg == "") || (!arg) ) {
        tell_object(ob, "\nShort description: ");
        tell_object(ob, "\tThis is how it will be seen in the player's inventory ");
        input_to("wshort", file, name, ob);
        return 1;
    }

    write_file(file, "\tset_short(\"" + arg + "\");\n");
        
    tell_object(ob, "Enter a long description for this weapon: \n");
    rm("/wizards/"+ob->query_name()+"/"+name+".tmp");
    ob->edit("/wizards/"+ob->query_name()+"/"+name+".tmp","wlong",this_object(),({file,name,ob}));

    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wlong( mixed *args ){
    string arg, file, name;
    object ob;

    file = args[0];
    name = args[1];
    ob   = args[2];

    arg = read_file("/wizards/"+ob->query_name()+"/" + name + ".tmp");

    write_file(file, "\tset_long( @LONGTEXT\n" + arg +
            "LONGTEXT\n     );\n");

    tell_object(ob, "\nEnter the weapon type of this weapon.");
    tell_object(ob, "\nChose from: Blunt, Knife, Blade, Two handed:  ");
    input_to("wtype", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wtype( string arg, string file, string name, object ob )  {
    string type;
    type = implode(WEAPON_TYPES, ", ");

    if( (arg == " ") || (arg == "") || (!arg) ) {
        tell_object(ob, "\nEnter the weapon type of this weapon.\n");
        tell_object(ob, "\nChose from: "+type+"  ");
        input_to("wtype", file, name, ob);
        return 1;
    }

    if (member_array(lower_case(arg), WEAPON_TYPES) < 0) {
        tell_object(ob, "\nEnter the weapon type of this weapon.\n");
        tell_object(ob, "\nChoose from: "+type+" ");
        input_to("wtype", file, name, ob);

        return 1;
    }

    write_file(file, "\tset_type(\""+lower_case(arg)+"\");\n");
    weapon_type = arg;
       
    tell_object(ob,"\nEnter the weight of this weapon (just a number): "); 
    input_to("wweight", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wweight( string arg, string file, string name, object ob )  {
    int mass, min_weight;

    min_weight = WEAPON_MIN_WEIGHT[weapon_type];

    if ( arg == "" ||  arg == " "  ||  !arg ) {
        tell_object(ob, "\nEnter the weight of this weapon (a number):  ");
        input_to("wweight", file, name, ob);
        return 1;
    }

    if (!sscanf(arg, "%d", mass))  {
        tell_object(ob, "\nEnter a number for the weight:  ");
        input_to("wweight", file, name, ob);
        return 1;
    }

    if (mass < min_weight)  {
        tell_object(ob, "\nThe min weight for a weapon of type "+weapon_type+
                    " is "+min_weight+". ");
        input_to("wweight", file, name, ob);
        return 1;
    }

    write_file(file, "\tset_weight("+arg+");\n");
    tell_object(ob, "\nEnter the value of the weapon (what is sells for): ");
    input_to("wvalue", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wvalue( int arg, string file, string name, object ob )  {
    int worth, min_value, max_value;

    min_value = WEAPON_MIN_VALUE[weapon_type];
    max_value = WEAPON_MAX_VALUE[weapon_type];

    if ( arg == "" ||  arg == " "  ||  !arg )  {
        tell_object(ob, "\nEnter what the weapon sells for (a number):  ");
        input_to("wvalue", file, name, ob);
        return 1;
    }

    if (!sscanf(arg, "%d", worth))  {
        tell_object(ob, "\nEnter a number to be the selling value:  ");
        input_to("wvalue", file, name, ob);
        return 1;
    }

    if (worth < min_value)  {
        tell_object(ob, "\nThe min value for a type "+weapon_type+" is "+
                    min_value+".  ");
        input_to("wvalue", file, name, ob);
        return 1;
    }

    if (worth > max_value)  {
        tell_object(ob, "\nThe max value for a type "+weapon_type+" is "+
                    max_value+".  ");
        input_to("wvalue", file, name, ob);
        return 1;
    }

    write_file(file, "\tset_value("+arg+");\n");

    tell_object(ob, "\nEnter the weapon class of this weapon:  ");
    tell_object(ob, "\t( 0 is the worse, 20 is the best  ) ");
    input_to("wclass", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wclass( int arg, string file, string name, object ob )  {
int class, min_wc, max_wc;

    min_wc = WEAPON_MIN_WC[weapon_type];
    max_wc = WEAPON_MAX_WC[weapon_type];

    if( arg == " "  ||  arg == ""  ||  !arg ) {
        tell_object(ob, "\nEnter the weapon class of this weapon:  ");
        tell_object(ob, "\t( 0 is the worse, 20 is the best ) ");
        input_to("wclass", file, name, ob);
        return 1;
    }
    
    if (!sscanf(arg, "%d", class ))  {
        tell_object(ob, "\nEnter a number to be the weapon class:  ");
        input_to("wclass", file, name, ob);
        return 1;
    }
        
    if (class > max_wc )  {
        tell_object(ob, "\nThe weapon class of a "+weapon_type+" must be "+
                    "less than "+max_wc+".");
        input_to("wclass", file, name, ob);
        return 1;
    }

    if (class < min_wc )  {
        tell_object(ob, "\nThe weapon class of a "+weapon_type+" must be "+
                    "greater than "+min_wc+".");
        input_to("wclass", file, name, ob);
        return 1;
    }


     write_file(file, "\tset_wc("+arg+");\n");

     tell_object(ob, "\nEnter the armour class of the weapon: ");
     tell_object(ob, "\t( 0 is the worse, 3 is the best ) ");
     input_to("waclass", file, name, ob);
     return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int waclass(string arg, string file, string name, object ob)  {
int prot, max_ac, min_ac;

    max_ac = WEAPON_MAX_AC[weapon_type];
    min_ac = WEAPON_MIN_AC[weapon_type];

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
        tell_object(ob, "\nEnter the armour class of the weapon: ");
        tell_object(ob, "\t( 0 is the worse, 3 is the best ) ");
        input_to("waclass", file, name, ob);
        return 1;
    }

    if (!sscanf(arg, "%d", prot))  {
        tell_object(ob, "\nThe armour class of the weapon must be a number: ");
        input_to("waclass", file, name, ob);
        return 1;
    }

    if (prot > max_ac)  {
        tell_object(ob, "\nThe armour class  of a "+weapon_type+" must be "+
                    "less than "+max_ac+". ");
        input_to("waclass", file, name, ob);
        return 1;
    }

    if (prot < min_ac)  {
        tell_object(ob, "\nThe armour class  of a "+weapon_type+" must be "+
                    "greater than "+min_ac+". ");
        input_to("waclass", file, name, ob);
        return 1;
    }

    write_file(file, "\tset_ac("+arg+");\n");

    tell_object(ob,"\nWant to make a special wield message [ yes : no ]? ");
    input_to("wield_mes1", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wield_mes1(string arg, string file, string name, object ob)  {

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
        tell_object(ob,"\nWant to make a special wield message [ yes : no ]? ");
        input_to("wield_mes1", file, name, ob);
        return 1;
    }

    if (lower_case(arg) == "yes"  || lower_case(arg) == "y")  {
        tell_object(ob,"\nEnter the message a player will see when the weapon "+
                    "is wielded: "); 
        input_to("wield_mess2", file, name, ob);
        return 1;
    }

    if (lower_case(arg) == "no"  || lower_case(arg) == "n")  {
        tell_object(ob, "\Want to make a special unwield message [ yes : no ] ? ");
        input_to("unwield_mes1", file, name, ob);
        return 1;
    }

    tell_object(ob, capitalize(arg)+" is not a valid choice [ yes : no ] ");
    input_to("wield_mes1", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wield_mess2(string arg, string file, string name, object ob)  {

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
        tell_object(ob,"\nEnter the message a player will see when the weapon "+
                    "is wielded: "); 
        input_to("wield_mess2", file, name, ob);
        return 1;
    }

    write_file(file, "\tset_wield(\""+arg+"\");\n");

    tell_object(ob,"\nWant to make a special unwield message [ yes : no ] ? ");
    input_to("unwield_mes1", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int unwield_mes1(string arg, string file, string name, object ob)  {

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
        tell_object(ob,"\nWant to make a special unwield message [ yes : no ]? ");
        input_to("unwield_mes1", file, name, ob);
        return 1;
    }

    if (lower_case(arg) == "yes"  || lower_case(arg) == "y")  {
        tell_object(ob,"\nEnter the message a player will see when the weapon "+
                    "is unwielded: "); 
        input_to("unwield_mess2", file, name, ob);
        return 1;
    }
    if (lower_case(arg) == "no"  || lower_case(arg) == "n")  {
        tell_object(ob,"\nDo you want the weapon to be able to poison its "+
                    "victim? [ yes : no ] ? ");
        input_to("poison", file, name, ob);
        return 1;
    }

    tell_object(ob, capitalize(arg)+" is not a valid choice [ yes : no ] ");
    input_to("unwield_mes1", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int unwield_mess2(string arg, string file, string name, object ob)  {

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
        tell_object(ob,"\nEnter the message a player will see when the weapon "+
                    "is unwielded: "); 
        input_to("unwield_mess2", file, name, ob);
        return 1;
    }

    write_file(file, "\tset_unwield(\""+arg+"\");\n");
    
    tell_object(ob,"\nDo you want the weapon to be able to poison its "+
                   "victim? [ yes : no ] ? ");
    input_to("poison", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int poison(string arg, string file, string name, object ob)  {

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
        tell_object(ob,"\nDo you want the weapon to be able to poison its "+
                    "victim? [ yes : no ] ? ");
        input_to("poison", file, name, ob);
        return 1;
    }

    if ( lower_case(arg) == "y"  || lower_case(arg) == "yes" )  {
         tell_object(ob,"\nWhat do you want the strength of the poison to "+
                     "be? ( a number, 40 is consider strong ) : ");
         input_to("poison2", file, name, ob);
         return 1;
     }

    if ( lower_case(arg) == "n"  || lower_case(arg) == "no" )  {
        tell_object(ob, "\nDo you want the weapon to decay? (decrease its "+
                    "weapon class with use) [ yes : no ] ");
        input_to("decay", file, name, ob);
        return 1;
    }

    tell_object(ob, capitalize(arg)+" is not a valid choice.  [ yes : no ] ");
    input_to("poison1", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int poison2(string arg, string file, string name, object ob)  {
    int strength;

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
         tell_object(ob,"\nWhat do you want the strength of the poison to "+
                     "be? ( a number, 40 is consider strong ) : ");
         input_to("poison2", file, name, ob);
         return 1;
    }

    if (!sscanf(arg, "%d", strength))  {
        tell_object(ob, "\n Posion strength must be a number. ");
        tell_object(ob, "\t Enter a number to be the poison strength. ");
        input_to("poison2", file, name, ob);
        return 1;
    }

    if (strength > 40)  {
        tell_object(ob, "\nPoison strength should be less than 40.  ");
        tell_object(ob, "\t Enter a number to be the poison strength. ");
        input_to("poison2", file, name, ob);
        return 1;
    }

    if (strength < 0)  {
        tell_object(ob, "\nPoison strength should be greater than 0.  ");
        tell_object(ob, "\t Enter a number to be the poison strength. ");
        input_to("poison2", file, name, ob);
        return 1;
    }

    write_file(file, "\tadd_poisoning("+arg+");\n");

    tell_object(ob,"\nDo you want the weapon to decay? ( Lose weapon "+
                "class with use? ");
    input_to("decay", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int decay(string arg, string file, string name, object ob)  {

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
        tell_object(ob,"\nDo you want the weapon to decay? ( Lose weapon "+
                    "class with use? ");
        input_to("decay", file, name, ob);
        return 1;
    }

    if ( lower_case(arg) == "yes"  ||  lower_case(arg) == "y" )  {
         tell_object(ob,"\nEnter the number of hits before the weapon decreases "+
                     "one point in weapon class: ");
         input_to("decay2", file, name, ob);
         return 1;
    }

    if ( lower_case(arg) == "no"  ||  lower_case(arg)  == "n")  {
        wdone(file, name, ob);
        return 1;
    }

    tell_object(ob, "\n"+capitalize(arg)+" is not a valid choice [ yes : no ] ");
    input_to("decay", file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int decay2(string arg, string file, string name, object ob)  {
    int damage;

    if ( arg == ""  ||  arg == " "  ||  !arg )  {
        tell_object(ob,"\nEnter the number of hits before the weapon decreases "+
                     "one point in weapon class: ");
        input_to("decay2", file, name, ob);
        return 1;
    }

    if (!sscanf(arg, "%d", damage))  {
        tell_object(ob,"\nThe damage must be a number. ");
        input_to("damage2", file, name, ob);
        return 1;
    }

    if (damage < 0 )  {
        tell_object(ob,"\nThe number for decay must be greater than zero : ");
        input_to("decay2", file, name, ob);
        return 1;
    }

    write_file(file, "\set_decay_rate("+arg+");\n");

    wdone(file, name, ob);
    return 1;
}

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
int wdone(string file, string name, object ob)
{
        write_file(file, @FILETEXT
}

void init()
{
        ::init();
        // Place add_action()s here.
}

/* End of File */

FILETEXT
);


write_file("/realms/qdog/log/makeweapon", ob->query_cap_name()+" created "+file+"  "+ctime(time())+".\n");

        seteuid(getuid());

        tell_object(ob,"File: " + file + " -- Created.\n");
        return 1;
	destruct(this_object());

  }


