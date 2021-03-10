#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help(){
    write("Syntax:  renchant <name> || renchant <name> <on>|<off> <reason>\n");
    write("renchant <name> will return the restriction of the "
    "enchant command for the <name> specified.  If they are "+
    "restricted then %^RED%^RESTRICTED%^RESET%^ will be returned "+
    "if they are then %^YELLOW%^unrestricted%^RESET%^ will be "+
    "returned.\n");
    write("renchant <name> <on>|<off> <reason> will either "+
    "restrict or unrestrict the use of the enchant command "+
    "for the person specified, <on> restricts the enchant "+
    "command and <off> unrestricts the command.  A <reason> is "+
    "required and will be added to their notes.");
    return 1;
}

int cmd_renchant(string str){
    string per, state, reason, notestring;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) {
        help();
        write("Incorrect syntax.");
        return 1;
    }
    if(sscanf(str,"%s %s %s",per,state,reason) == 3) {
        per = lower_case(per);
        if(!user_exists(per)) {
            write("No such character exists.");
            return 1;
        }
        
        switch(state) {
            case "on":
                if((int)SAVE_D->is_member("enchant_restricted",per) != -1) {
                    write(capitalize(per)+ " is already "+
                    "%^RED%^RESTRICTED%^RESET%^ from use of the "+
                    "enchant command.  See their notes for the "+
                    "reason.");
                    return 1;
                    break;
                }
                write(capitalize(per)+" is now %^RED%^RESTRICTED"+
                "%^RESET%^ from use of the enchant command.");
                SAVE_D->set_value("enchant_restricted",per);
                notestring = "add "+per+ " %^RED%^Restricted%^RESET%^ "+
                "from use of enchant command because: "+
                "%^B_CYAN%^%^YELLOW%^"+reason+"%^RESET%^";
                break;
            case "off":
                if((int)SAVE_D->is_member("enchant_restricted",per) == -1) {
                    write(capitalize(per) + " is already "+
                    "%^YELLOW%^unrestricted%^RESET%^ from use of the "+
                    "enchant command.");            
                    return 1;
                    break;
                }
                write(capitalize(per)+" is now %^YELLOW%^unrestricted"+
                "%^RESET%^ from use of the enchant command.");
                SAVE_D->remove_name_from_array("enchant_restricted",per);
                notestring = "add "+per+ " %^YELLOW%^Unrestricted%^RESET%^ "+
                "from use of enchant command because: "+
                "%^B_CYAN%^%^YELLOW%^" +reason+"%^RESET%^";
                break;
            default:
                help();
                write("Incorrect syntax.");
                return 1;
       }        
       "/cmds/avatar/_note"->cmd_note(notestring);
       return 1;
    }
    
    if(sscanf(str,"%s",per) == 1) {
        per = lower_case(per);
        if(!user_exists(per)) {
            write("No such character exists.");
            return 1;
        }
        if((int)SAVE_D->is_member("enchant_restricted",per) != -1) {
            write(capitalize(per)+" is currectly %^RED%^"+
            "RESTRICTED%^RESET%^ from use of the enchant command.  "+
            "See their notes for the reason.");
            return 1;
        }
        write(capitalize(per)+" is currently %^YELLOW%^unrestricted"+
        "%^RESET%^ from use of the enchant command.");
        return 1;
    }

    help();
    write("Incorrect syntax.");
    return 1;
   
}