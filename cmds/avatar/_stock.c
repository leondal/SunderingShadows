#include <std.h>
#include <daemons.h>

#define SEARCH_D "/daemon/search_d.c"

string lower_map(string str);
int type_check(string str);
int extra_check(string str);
varargs int help(object tp,string str);

string lower_map(string str) { return lower_case(str); }

int type_check(string str)
{
    if(!stringp(str)) { return 0; }
    str = lower_case(str);
    switch(str)
    {
    case    "armor":    return 1;
    case    "weapon":   return 1;
    case    "clothing": return 1;
    case    "mundane":  return 1;
    case    "misc":     return 1;
    case    "jewelry":  return 1;
    default:            return 0;
    }
    return 0;
}

int extra_check(string str)
{
    if(!stringp(str)) { return 0; }
    str = lower_case(str);
    switch(str)
    {
    case "special":  return 1;
    case "excluded": return 1;
    default:         return 0;
    }
    return 0;
}

int cmd_stock(string str)
{
    object obj;
    string *stuff,what,new_type,old_type,name,file;
    int num,level,amount;
    if(!objectp(TP))  { return 0; }
    if(!stringp(str)) { return help(TP); }
    
    stuff = explode(str," ");
    stuff = map_array(stuff,"lower_map",TO);
    num   = sizeof(stuff);
    
    
    switch(stuff[0])
    {
    case "display":
    case "list":
        if(num < 2) { return help(TP,"list"); }
        switch(stuff[1])
        {
        case "levels":
        case "level":            
            if(num < 3) { return help(TP,"list"); }
            switch(stuff[2])
            {
            case "item":
            case "items":
                SEARCH_D->display_levels("item",TP);
                return 1;
            case "room":
            case "rooms":
                SEARCH_D->display_levels("room",TP);
                return 1;
            case "here":
                num = SEARCH_D->get_room_level(base_name(ETP));
                tell_object(TP,"\n%^RESET%^%^BOLD%^Level%^RESET%^:%^CYAN%^ "+num+"   %^RESET%^"+base_name(ETP)+"\n");
                return 1;
            default:
                if(obj=present(stuff[2],TP) || obj=present(stuff[2],ETP))
                {
                    num = SEARCH_D->get_item_level(base_name(obj));
                    tell_object(TP,"\n%^RESET%^%^BOLD%^Level%^RESET%^:%^CYAN%^ "+num+"   %^RESET%^"+base_name(obj)+"\n");
                    return 1;
                }
                else { return help(TP,"list"); }
            }

        case "item":
        case "items":
            if(num < 3) { return help(TP,"list"); }
            if(!type_check(stuff[2]) && !extra_check(stuff[2])) { return help(TP,"list"); }
            SEARCH_D->display_array(stuff[2],TP);
            return 1;  
        default:
            if(!type_check(stuff[1])) { return help(TP,"list"); }
            SEARCH_D->display_table(stuff[1],TP);
            return 1;
        }

    case "add":
        if(num < 2) { return help(TP,"add"); }
        switch(stuff[1])
        {
        case "special":
            if(num >= 4)
            {
                stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
                what = implode(stuff," ");
                if(obj=present(what,TP) || obj=present(what,ETP))
                {
                    tell_object(TP,"%^RESET%^%^BOLD%^"+obj->query("short")+"   "+base_name(obj)+" added.");
                    SEARCH_D->add_special_item(obj);
                    return 1;
                }
            }            
            else if(num < 4 && obj=present(stuff[2],TP) || obj=present(stuff[2],ETP))
            {
                tell_object(TP,"%^RESET%^%^BOLD%^"+obj->query("short")+"   "+base_name(obj)+" added.");
                SEARCH_D->add_special_item(obj);
                return 1;
            }
            else if(strsrch(stuff[2],"/") != -1)
            {
                stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
                what = replace_string(stuff[0],".c","");
                if(file_exists(what+".c"))
                {
                    tell_object(TP,"%^RESET%^%^BOLD%^"+what+" added.");
                    SEARCH_D->add_special_item(what);
                    return 1;
                }
            }
            else { return help(TP,"add"); }
            return 1;

        case "excluded":
            if(num >= 4)
            {
                stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
                what = implode(stuff," ");
                if(obj=present(what,TP) || obj=present(what,ETP))
                {
                    tell_object(TP,"%^RESET%^%^BOLD%^"+obj->query("short")+" "+base_name(obj)+" excluded.");
                    SEARCH_D->add_excluded_item(obj);
                    return 1;
                }
            }            
            else if(num < 4 && obj=present(stuff[2],TP) || obj=present(stuff[2],ETP))
            {
                tell_object(TP,"%^RESET%^%^BOLD%^"+obj->query("short")+" "+base_name(obj)+" excluded.");
                SEARCH_D->add_excluded_item(obj);
                return 1;
            }
            else if(strsrch(stuff[2],"/") != -1)
            {
                stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
                what = replace_string(stuff[0],".c","");
                if(file_exists(what+".c"))
                {
                    tell_object(TP,"%^RESET%^%^BOLD%^"+what+" excluded.");
                    SEARCH_D->add_excluded_item(what);
                    return 1;
                }
            }
            else { return help(TP,"add"); }
            return 1;
            
        default:        
            if(obj=present(stuff[1],TP) || obj=present(stuff[1],ETP))
            {
                tell_object(TP,"%^RESET%^%^BOLD%^"+obj->query("short")+" "+base_name(obj)+" added.");
                SEARCH_D->add_object(obj);
                return 1;
            }
            else if(strsrch(stuff[1],"/") != -1)
            {
                if(!file_exists(stuff[1]))
                {
                    tell_object(TP,"Invalid file name.");
                    return 1;
                }
                SEARCH_D->add_object(obj=new(stuff[1]));
                tell_object(TP,"%^RESET%^%^BOLD%^"+obj->query("short")+" "+base_name(obj)+" added.");
                if(objectp(obj)) { obj->remove(); }
                return 1;
            }
            else 
            {
                stuff -= ({ stuff[0] });
                what = implode(stuff," ");
                if(obj=present(what,TP) || obj=present(what,ETP)) 
                {
                    tell_object(TP,"%^RESET%^%^BOLD%^"+obj->query("short")+" "+base_name(obj)+" added.");
                    SEARCH_D->add_object(obj);
                    return 1; 
                }
            }
            return help(TP,"add");
        }


    case "change":
        if(num < 2) { return help(TP,"change"); }
        switch(stuff[1])
        {
        case "type":
            if(num < 3) { return help(TP,"change"); }
            old_type = stuff[num-2];
            new_type = stuff[num-1];
            stuff -= ({ stuff[num -1] }); stuff -= ({ stuff[num -2] });
            stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
            what = implode(stuff, " ");
            if(!type_check(old_type)) { return help(TP,"change"); }
            if(!type_check(new_type)) { return help(TP,"change"); }
            if(objectp(obj=present(what,TP)) || objectp(obj=present(what,ETP)))
            {
                tell_object(TP,"Changing item "+base_name(obj)+" type from "+old_type+" to "+new_type+"");
                SEARCH_D->change_item_type(obj,old_type,new_type);
                return 1;
            }
            else if(strsrch(what,"/") != -1)
            {
                if(!file_exists(what+".c")) { return help(TP,"change"); }
                tell_object(TP,"Changing item "+what+" type from "+old_type+" to "+new_type+"");
                SEARCH_D->change_item_type(what,old_type,new_type);
                return 1;
            }
            else 
            {
                what = SEARCH_D->get_file_from_name(what,old_type);
                if(!file_exists(what+".c")) { return help(TP,"change"); }
                tell_object(TP,"Changing item "+what+" type from "+old_type+" to "+new_type+"");
                SEARCH_D->change_item_type(what,old_type,new_type);
                return 1;
            }

        case "level":
            if(num < 3) { return help(TP,"change"); }
            what = stuff[num-1];
            stuff -= ({ stuff[num -1] });
            stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
            level = to_int(what);
            what = implode(stuff, " ");
            if(objectp(obj=present(what,TP)) || objectp(obj=present(what,ETP)))
            {
                tell_object(TP,"Changing item "+base_name(obj)+" level to "+level+"");
                SEARCH_D->change_item_level(obj,level);
                return 1;
            }
            else if(strsrch(what,"/") != -1)
            {
                if(!file_exists(what+".c")) { return help(TP,"change"); }
                tell_object(TP,"Changing item "+what+" level to "+level+"");
                SEARCH_D->change_item_level(what,level);
                return 1;
            }
            else { return help(TP,"change"); }

        case "amount":
        case "number":
        case "num":
            if(num < 3) { return help(TP,"change"); }
            what = stuff[num-1];
            stuff -= ({ stuff[num -1] });
            stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
            amount = to_int(what);
            what = implode(stuff, " ");
            if(objectp(obj=present(what,TP)) || objectp(obj=present(what,ETP)))
            {
                tell_object(TP,"Adding "+amount+" to "+base_name(obj)+"");
                SEARCH_D->change_item_amount(obj,amount);
                return 1;
            }
            else if(strsrch(what,"/") != -1)
            {
                if(!file_exists(what+".c")) { return help(TP,"change"); }
                tell_object(TP,"Adding "+amount+" to "+what+"");
                SEARCH_D->change_item_amount(what,amount);
                return 1;
            }
            else { return help(TP,"change"); }

        case "name":
            if(num < 3) { return help(TP,"change"); }

            old_type = stuff[2];
            stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
            what = implode(stuff, " ");
            if(sscanf(what,"%s to %s",name, file) != 2) { return help(TP,"change"); }
            if(objectp(obj=present(name,TP)) || objectp(obj=present(name,ETP)))
            {
                tell_object(TP,"Changing name of "+base_name(obj)+" to "+file+"");
                SEARCH_D->change_item_name(old_type,obj,file);
                return 1;
            }
            else if(strsrch(name,"/") != -1)
            {
                if(!file_exists(name+".c")) { return help(TP,"change"); }
                tell_object(TP,"Changing name of "+name+" to "+file+"");
                SEARCH_D->change_item_name(old_type,name,file);
                return 1;
            }
            else { return help(TP,"change"); }
        default:
            return help(TP,"change");
        }


    case "delete":
    case "remove":
        if(num < 2) { return help(TP,"remove"); }
        switch(stuff[1])
        {
        case "item":
        case "object":
            if(num < 3) { return help(TP,"remove"); }
            old_type = stuff[num-1];
            stuff -= ({ stuff[num -1] });
            stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
            what = implode(stuff, " ");
            if(!type_check(old_type)) 
            { 
                tell_object(TP,"Invalid type.");
                return help(TP,"remove"); 
            }
            if(objectp(obj=present(what,TP)) || objectp(obj=present(what,ETP)))
            {
                tell_object(TP,"Deleting "+base_name(obj)+" from "+old_type+" list");
                SEARCH_D->delete_item_from_table(obj,old_type);
                return 1;
            }
            else if(strsrch(what,"/") != -1)
            {
                if(!file_exists(what+".c")) { return help(TP,"change"); }
                tell_object(TP,"Deleting "+what+" from "+old_type+" list");
                SEARCH_D->delete_item_from_table(what,old_type);
                return 1;
            }
            else if(strsrch(what,"/") == -1)
            {
                what = SEARCH_D->get_file_from_name(what,old_type);
                if(!file_exists(what+".c")) { return help(TP,"remove"); }
                tell_object(TP,"Deleting "+what+" from "+old_type+" list");
                SEARCH_D->delete_item_from_table(what,old_type);
                return 1;
            }
            else { return help(TP,"remove"); }

        case "file":
            if(num < 3) { return help(TP,"remove"); }
            old_type = stuff[num-1];
            stuff -= ({ stuff[num -1] });
            stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
            what = implode(stuff, " ");
            if(!type_check(old_type) && !extra_check(old_type)) { return help(TP,"remove"); }
            if(objectp(obj=present(what,TP)) || objectp(obj=present(what,ETP)))
            {
                tell_object(TP,"Deleting "+base_name(obj)+" from "+old_type+" array");
                SEARCH_D->remove_file_from_array(old_type,base_name(obj));
                return 1;
            }
            else if(strsrch(what,"/") != -1)
            {
                if(!file_exists(what+".c")) { return help(TP,"change"); }
                tell_object(TP,"Deleting "+what+" from "+old_type+" array");
                SEARCH_D->remove_file_from_array(old_type,what);
                return 1;
            }
            else if(strsrch(what,"/") == -1)
            {
                what = SEARCH_D->get_file_from_name(what,old_type);
                if(!file_exists(what+".c")) { return help(TP,"remove"); }
                tell_object(TP,"Deleting "+what+" from "+old_type+" array");
                SEARCH_D->remove_file_from_array(old_type,what);
                return 1;
            }
            else { return help(TP,"remove"); }

        default: 
            return help(TP,"remove");
        }

    case "create":
    case "make":
        if(num < 2) { return help(TP,"create"); }
        old_type = stuff[1];
        stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
        what = implode(stuff, " ");
        if(!type_check(old_type) && !extra_check(old_type)) { return help(TP,"create"); }

        else if(strsrch(what,"/") != -1)
        {
            if(!file_exists(what+".c")) { return help(TP,"create"); }
            tell_object(TP,"Creating item "+what+"");
            SEARCH_D->create_item(TP,what);
            return 1;
        }
        else if(strsrch(what,"/") == -1)
        {
            what = SEARCH_D->get_file_from_name(what,old_type);
            if(!file_exists(what+".c")) { return help(TP,"create"); }
            tell_object(TP,"Creating item "+what+"");
            SEARCH_D->create_item(TP,what);
            return 1;
        }
        else { return help(TP,"create"); }

    case "lock":
        if(num < 2) { return help(TP,"lock"); }
        old_type = stuff[1];
        stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
        what = implode(stuff, " ");
        if(!type_check(old_type)) 
        { 
            tell_object(TP,"Invalid type.");
            return help(TP,"lock"); 
        }
        if(objectp(obj=present(what,TP)) || objectp(obj=present(what,ETP)))
        {
            tell_object(TP,"Locking "+base_name(obj)+"");
            SEARCH_D->lock_item(obj,old_type);
            return 1;
        }
        else if(strsrch(what,"/") != -1)
        {
            if(!file_exists(what+".c")) { return help(TP,"lock"); }
            tell_object(TP,"Locking "+what+"");
            SEARCH_D->lock_item(what,old_type);
            return 1;
        }
        else if(strsrch(what,"/") == -1)
        {
            what = SEARCH_D->get_file_from_name(what,old_type);
            if(!file_exists(what+".c")) { return help(TP,"lock"); }
            tell_object(TP,"Locking "+what+"");
            SEARCH_D->lock_item(what,old_type);
            return 1;
        }
        else { return help(TP,"lock"); }

    case "unlock":
        if(num < 2) { return help(TP,"create"); }
        old_type = stuff[1];
        stuff -= ({ stuff[0] }); stuff -= ({ stuff[0] });
        what = implode(stuff, " ");
        if(!type_check(old_type)) 
        { 
            tell_object(TP,"Invalid type.");
            return help(TP,"unlock"); 
        }
        if(objectp(obj=present(what,TP)) || objectp(obj=present(what,ETP)))
        {
            tell_object(TP,"Unlocking "+base_name(obj)+"");
            SEARCH_D->unlock_item(obj,old_type);
            return 1;
        }
        else if(strsrch(what,"/") != -1)
        {
            if(!file_exists(what+".c")) { return help(TP,"unlock"); }
            tell_object(TP,"Unlocking "+what+"");
            SEARCH_D->unlock_item(what,old_type);
            return 1;
        }
        else if(strsrch(what,"/") == -1)
        {
            what = SEARCH_D->get_file_from_name(what,old_type);
            if(!file_exists(what+".c")) { return help(TP,"unlock"); }
            tell_object(TP,"Unlocking "+what+"");
            SEARCH_D->unlock_item(what,old_type);
            return 1;
        }
        else { return help(TP,"unlock"); }

    case "help":
        if(num < 2) { return help(TP); }
        else { return help(TP,stuff[1]); }

    default:
        return help(TP);
    }
    return 1;
}












varargs int help(object tp,string str)
{
    if(!objectp(tp)) 
    { 
        if(objectp(TP)) { tp = TP; }
        else { return 0; }
    }
    
    if(!stringp(str)) 
    {
        tell_object(tp,"The stock command is used to display lists of treasure that "
            "players are able to find with random searches all over the mud.  The "
            "command has several functions to allow the imms to alter various things "
            "about the items, including min level to find, and the amount of items "
            "that are 'stored'.  The amount of items is directly related to the "
            "chance for a player to find them.  Higher level items will be more rare "
            "regardless of how many of them there are, also, lower level items will be "
            "more common, even if there is a small amount of them.  Following is a list "
            "of all the functions of the command.  Type stock help <topic> for a more "
            "detailed explaination.\n");
        tell_object(tp,"\t%^RESET%^%^BOLD%^"+arrange_string("list",20)  +"add");
        tell_object(tp,"\t%^RESET%^%^BOLD%^"+arrange_string("change",20)+"remove");
        tell_object(tp,"\t%^RESET%^%^BOLD%^"+arrange_string("create",20)+"lock");
        tell_object(tp,"\t%^RESET%^%^BOLD%^"+arrange_string("unlock",20)+"help");
        return 1;
    }
    switch(str)
    {
    case "list":
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock list level items%^RESET%^");
        tell_object(tp,"%^RESET%^stock list level items will return a list of all "
            "items and the levels that they have been set to.  This is the "
            "lowest level player and room at which the item can be found.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock list level rooms%^RESET%^");
        tell_object(tp,"%^RESET%^stock list level rooms will return a list of all "
            "directories that have been asigned levels.  This is also the "
            "minimum level of items that can be found in the room with the "
            "global search.  If a directory isn't in this list, it is assumed "
            "to be Level 1.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock list level here%^RESET%^");
        tell_object(tp,"%^RESET%^stock list level here will return the level of the "
            "room that you are currently standing in.  This is useful for "
            "a quick reference of what level items people will find in "
            "the area.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock list level <item>%^RESET%^");
        tell_object(tp,"%^RESET%^stock list level <item> will return the level of the "
            "item that you target.  It first looks for the item in your "
            "inventory, and then for the item in the room.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock list items <type>%^RESET%^");
        tell_object(tp,"%^RESET%^stock list items <type> will return a list of all "
            "items of <type> that are currently saved.  Type must be one "
            "of the following: %^RESET%^%^BOLD%^weapon, armor, clothing, "
            "jewelry, misc, mundane, special or excluded.%^RESET%^");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock list <type>%^RESET%^");
        tell_object(tp,"%^RESET%^stock list <type> will return a table displaying "
            "all important information about <type>.  This is used to show "
            "common names of items, as well as level and amount of items.  "
            "Valid types are: %^RESET%^%^BOLD%^weapon, armor, clothing, "
            "jewelry, misc and mundane%^RESET%^");
        break;
    case "add":
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock add special <item>");
        tell_object(tp,"%^RESET%^stock add special <item> is used to add items "
            "to the special list.  These are items that need some special "
            "function to create.  Any items on this list will need "
            "extra code to handle, and should only be used if you intend "
            "to write the code for it.  <item> can be an item currently "
            "in your inventory or in the room, or the file name of "
            "the item that you would like to add.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock add excluded <item>");
        tell_object(tp,"%^RESET%^stock add excluded <item> is used to add items "
            "to the excluded list.  This items will never be added to the "
            "table that the players are able to find.  This is useful for "
            "items that are just not worth finding, or are too special "
            "to be found.  <item> can be an object in the room with you "
            "or in your inventory or the file name of the object.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock add <item>");
        tell_object(tp,"%^RESET%^stock add <item> will add <item> to the list so that "
            "players are able to find it with searches.  <item> can be "
            "any item in your inventory or in the room, or the file name "
            "of the item.");
        break;
    case "change":
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock change type <item> <old type> <new type>");
        tell_object(tp,"%^RESET%^stock change type <item> <old type> <new type> is used "
            "to change the type of an object.  For instance, if a ring is listed "
            "as armor, it can be changed to jewelry.  <item> can be any object in "
            "your inventory or the room, or the file name of the item that you "
            "want to change.  Valid types are: %^RESET%^%^BOLD%^weapon, armor, "
            "clothing, jewelry, misc and mundane.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock change level <item> <level>");
        tell_object(tp,"%^RESET%^stock change <item> <level> is used to change the "
            "level of an object.  This effects what level that players are "
            "able to find the object.  <item> can be any item in your "
            "inventory or the file name of the item.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock change amount <item> <amount>");
        tell_object(tp,"%^RESET%^stock change amount <item> <amount> ADDS amount "
            "to <item>.  This can be a positive or negative number, to "
            "allow the number of items to be raised or lowered.  This "
            "number effects the percent chance for that item to be "
            "found with searches.  <item> can be any item in your "
            "inventory or the file name of <item>.");
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock change name <type> <old name> to <new name>");
        tell_object(tp,"%^RESET%^stock change name <type> <old name> to <new name> is used "
            "to change the common name displayed in the list with (stock display <type>).  "
            "This has no effect on anything, other than the name displayed in the "
            "table.  It's used to keep things better organized.  <old name> can be the "
            "corresponding object in your inventory, or the file name of the object "
            "that you wish to change.  <new name> is the name that you want to change "
            "to.  <type> must be one of the following: %^RESET%^%^BOLD%^weapon, armor, "
            "clothing, jewelry, misc or mundane.");
        break;
    case "remove":
        tell_object(tp,"%^RESET%^%^BOLD%^\tUsage: stock remove item <item> <type>");
        tell_object(tp,"%^RESET%^stock remove item <item> <type> is used to "
            "remove an item from the list completely.  This is used "
            "to get bad items off the list.  <item> can be any item "
            "in your inventory or in the room, it can be the file "
            "name of <item> or the common name of <item>.  <type> "
            "must be one of the following: %^RESET%^%^BOLD%^weapon, "
            "armor, clothing, jewelry, misc, mundane.");
        tell_object(tp,"%^RESET%^%^BOLD%^\tUsage: stock remove file <file> <type>");
        tell_object(tp,"%^RESET%^stock remove file <file> <type> is used to remove "
            "a file from an array, such as to remove an excluded item or "
            "special item.  <item> can be any object in your inventory "
            "or in the room, or the file name of <item> or the common "
            "name of <item>.  <type> must be one of the following: "
            "%^RESET%^%^BOLD%^weapon, armor, clothing, jewelry, misc "
            "mundane, special or excluded.");
        break;
    case "create":
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock create <type> <item>");
        tell_object(tp,"%^RESET%^stock create <type> <item> is used to create "
            "an item and move it to the room you are in.  <item> "
            "must be either the file name of the item, or the item's "
            "common name.  <type> must be the type of the item that you "
            "want to create, and must be one of the following: %^RESET%^%^BOLD%^"
            "weapon, armor, clothing, jewelry, misc, mundane.");
        break;
    case "lock":
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock lock <type> <item>");
        tell_object(tp,"%^RESET%^stock lock <type> <item> locks the item "
            "so that the amount isn't reduced normally when a player "
            "finds one of that item.  This is useful for items that "
            "should be common to find in searches, such as gems, "
            "components, etc.  Locked items will have their amounts "
            "show up in red in the Num column of the display.  <item> "
            "can be any item in your inventory "
            "or in the room, or the file name or common name of <item>.  "
            "<type> must be one of the following: %^RESET%^%^BOLD%^weapon, "
            "armor, clothing, jewelry, misc or mundane.");
        break;
    case "unlock":
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock unlock <type> <item>");
        tell_object(tp,"%^RESET%^stock unlock <type> <item> is used to unlock "
            "previously locked items. <item> can be any item in your "
            "inventory or in the room, or the file name or common name of <item>.  "
            "<type> must be one of the following: %^RESET%^%^BOLD%^weapon, "
            "armor, clothing, jewelry, misc or mundane.");
        break;
    case "help":
        tell_object(tp,"\t%^RESET%^%^BOLD%^Usage: stock help <topic>");
        tell_object(tp,"%^RESET%^stock help <topic> is used to display "
            "more information about <topic>.");
        break;
    default:
        help(tp);
        break;
    }
    return 1;
}
