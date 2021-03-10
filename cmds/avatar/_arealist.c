#include <std.h>
#include <daemons.h>

int help();
int remove_location(string str,string location);
int header(string area,string what);
int footer();
int display_list(string name,string *aliases,string adjective,int bounty,int fine);
int is_location(string location);


int cmd_arealist(string str) 
{
    string name,adjective,*names,*commands,*locations,*aliases;
    int i,n,fine=0,bounty=0;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) { return help(); }    
    commands = explode(str," ");
    if(!sizeof(commands)) { return help(); }

    switch(commands[0])
    {
    case "locations":
        locations = AREALISTS_D->query_valid_locations();
        if(!pointerp(locations)) { write("There are no locations currently listed.\n"); return 1; }
        write("\n%^BLUE%^==== %^RESET%^%^BOLD%^Valid Locations%^RESET%^%^BLUE%^ ===================%^RESET%^\n");
        for(i=0;i<sizeof(locations);i++)
        {
            write("%^CYAN%^\t"+locations[i]+"%^RESET%^");
        }
        write("\n%^BLUE%^========================================%^RESET%^");        
        return 1;


    case "clean":
        if(!wizardp(TP)) { return 1; }
        write("This command is process intensive and should "
            "be used sparingly.");
        write("Cleaning Arealists...");
        AREALISTS_D->clean_criminals();
        write("Done.");
        return 1;

        
    case "add":
        if(sizeof(commands) < 2) { return help(); }
        switch(commands[1])
        {
        case "location":
            if(sizeof(commands) < 3) { return help(); }
            if(!wizardp(TP)) { return 1; }
            if(sizeof(AREALISTS_D->query_valid_locations()))
            {
                if(!AREALISTS_D->is_valid_location(commands[2]))
                {
                    AREALISTS_D->add_valid_location(commands[2]);
                    write("Location "+commands[2]+" added to valid locations.");
                    return 1;
                }
                else
                {
                    write(""+commands[2]+" is already listed as a valid location.");
                    return 1;
                }
            }
            else
            {
                AREALISTS_D->add_valid_location(commands[2]);
                write("%^BOLD%^Location "+commands[2]+" added.%^RESET%^");
                return 1;
            }

        case "wanted":
            if(sizeof(commands) < 4) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            AREALISTS_D->add_wanted(commands[3],commands[2],TP);
            return 1;

        case "bounty":
            if(sizeof(commands) < 5) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            AREALISTS_D->add_bounty(commands[3],commands[2],to_int(commands[4]),TP);
            return 1;

        case "fine":
            if(sizeof(commands) < 5) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            AREALISTS_D->add_fine(commands[3],commands[2],to_int(commands[4]),TP);
            return 1;

        case "jailer":
            if(sizeof(commands) < 4) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            AREALISTS_D->add_jailer(commands[3],commands[2],TP);
            return 1;


        case "alias":
            if(sizeof(commands) < 4) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            if(sizeof(commands) < 6) { return help(); }
            switch(commands[3])
            {
            case "wanted":
                AREALISTS_D->add_wanted_alias(commands[4],commands[5],commands[2],TP);
                return 1;
            case "jailer":
                AREALISTS_D->add_jailer_alias(commands[4],commands[5],commands[2],TP);
                return 1;
            case "prisoner":
                AREALISTS_D->add_prisoner_alias(commands[4],commands[5],commands[2],TP);
                return 1;
            case "fine":
                AREALISTS_D->add_fine_alias(commands[4],commands[5],commands[2],TP);
                return 1;
            default:
                return help();
            }
            return 1;
      
        default:
            return help();
        }
   

    case "remove":
        if(sizeof(commands) < 2) { return help(); }
        switch(commands[1])
        {
        case "location":
            if(sizeof(commands) < 3) { return help(); }
            if(!wizardp(TP)) { return 1; }
            if(AREALISTS_D->is_valid_location(commands[2]))
            {
                write("%^RED%^WARNING%^RESET%^: if location "+commands[2]+" is "
                    "not empty, ALL information for "+commands[2]+", including "
                    "wanted lists, fines, bounties, prisoners, and jailers will "
                    "be removed.  Are you sure you would like to continue?");
                write("Enter yes or no.");
                input_to("remove_location",commands[2]);
                return 1;
            }
            else
            {
                write(""+commands[2]+" is not a valid location, <arealist "
                    "locations> for a list of valid locations.  Note: "
                    "capitalization is important.");
                return 1;
            }

        case "wanted":
            if(sizeof(commands) < 4) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            if(!AREALISTS_D->is_wanted(commands[3],commands[2],TP))
            {
                write(""+commands[3]+" is not wanted in "+commands[2]+".");
                return 1;
            }
            AREALISTS_D->remove_wanted(commands[3],commands[2],TP);
            return 1;

        case "bounty":
            if(sizeof(commands) < 4) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            if(!AREALISTS_D->has_bounty(commands[3],commands[2],TP))
            {
                write(""+commands[3]+" does not have a bounty "
                    "in "+commands[2]+".");
                return 1;
            }
            AREALISTS_D->remove_bounty(commands[3],commands[2],TP);
            return 1;

        case "fine":
            if(sizeof(commands) < 4) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            if(!AREALISTS_D->has_fine(commands[3],commands[2],TP))
            {
                write(""+commands[3]+" does not have a fine "
                    "in "+commands[2]+".");
                return 1;
            }
            AREALISTS_D->remove_fine(commands[3],commands[2],TP);
            return 1;

        case "jailer":
            if(sizeof(commands) < 4) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            if(!AREALISTS_D->is_jailer(commands[3],commands[2],TP))
            {
                write(""+commands[3]+" is not a jailer in "+commands[2]+".");
                return 1;
            }
            AREALISTS_D->remove_jailer(commands[3],commands[2],TP);
            return 1;
      
        default:
            return help();
        }


    case "list":
        if(sizeof(commands) < 2) { return help(); }
        switch(commands[1])
        {        
        case "jailers":
            if(sizeof(commands) < 3) { return help(); }
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            names = AREALISTS_D->query_jailer_names(commands[2]);
            if(!sizeof(names))
            {
                write("No jailers listed for "+commands[2]+".");
                return 1;
            }
            
            header(commands[2],"Jailers");
            for(i=0;i<sizeof(names);i++)
            {
                adjective = AREALISTS_D->query_jailer_adjective(names[i],commands[2],TP);
                aliases   = AREALISTS_D->query_jailer_aliases(names[i],commands[2],TP);
                display_list(names[i],aliases,adjective,0,0);
            }
            footer();       
            return 1;

        case "prisoners":
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            names = AREALISTS_D->query_prisoner_names(commands[2]);
            if(!sizeof(names))
            {
                write("No prisoners listed for "+commands[2]+".");
                return 1;
            }            
            header(commands[2],"Prisoners");
            for(i=0;i<sizeof(names);i++)
            {
                if(AREALISTS_D->has_bounty(names[i],commands[2],TP))
                {
                    bounty = AREALISTS_D->query_bounty_amount(names[i],commands[2],TP);
                }
                if(AREALISTS_D->has_fine(names[i],commands[2],TP))
                {
                    fine = AREALISTS_D->query_fine_amount(names[i],commands[2],TP);
                }
                adjective = AREALISTS_D->query_prisoner_adjective(names[i],commands[2],TP);
                aliases   = AREALISTS_D->query_prisoner_aliases(names[i],commands[2],TP);
                display_list(names[i],aliases,adjective,bounty,fine);
            }
            footer();
            return 1;

        case "wanted":
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            names = AREALISTS_D->query_wanted_names(commands[2]);
            if(!sizeof(names))
            {
                write("No wanted listed for "+commands[2]+".");
                return 1;
            }            
            header(commands[2],"Wanted");
            for(i=0;i<sizeof(names);i++)
            {
                adjective = AREALISTS_D->query_wanted_adjective(names[i],commands[2],TP);
                aliases   = AREALISTS_D->query_wanted_aliases(names[i],commands[2],TP);
                if(AREALISTS_D->has_bounty(names[i],commands[2],TP))
                {
                    bounty = AREALISTS_D->query_bounty_amount(names[i],commands[2],TP);
                }
                if(AREALISTS_D->has_fine(names[i],commands[2],TP))
                {
                    fine = AREALISTS_D->query_fine_amount(names[i],commands[2],TP);
                }
                display_list(names[i],aliases,adjective,bounty,fine);
                bounty = 0; fine = 0;
            }
            footer();
            return 1;

        case "fines":
            if(!is_location(commands[2]))
            {
                write(""+commands[2]+" is not a valid location, "
                    "<arealist locations> for a list of all valid "
                    "locations.");
                return 1;
            }
            names = AREALISTS_D->query_fine_names(commands[2]);
            if(!sizeof(names))
            {
                write("No fines for "+commands[2]+".");
                return 1;
            }            
            header(commands[2],"Fines");
            for(i=0;i<sizeof(names);i++)
            {
                adjective = AREALISTS_D->query_fine_adjective(names[i],commands[2],TP);
                aliases   = AREALISTS_D->query_fine_aliases(names[i],commands[2],TP);
                if(AREALISTS_D->has_bounty(names[i],commands[2],TP))
                {
                    bounty = AREALISTS_D->query_bounty_amount(names[i],commands[2],TP);
                }
                if(AREALISTS_D->has_fine(names[i],commands[2],TP))
                {
                    fine = AREALISTS_D->query_fine_amount(names[i],commands[2],TP);
                }
                display_list(names[i],aliases,adjective,bounty,fine);
                bounty = 0; fine = 0;
            }
            footer();
            return 1;

        default:
            return help();
        }
    default:
        return help();
    }
    return 1;
}

int remove_location(string str,string location)
{
    if(str != "yes" && str != "no")
    {
        write("You must enter yes or no.");
        return 1;
    }
    if(str == "no") { write("Aborting..."); return 1; }
    if(str == "yes") 
    {
        AREALISTS_D->remove_valid_location(location);
        write("Location "+location+" removed from valid locations.");
        return 1;    
    }
}

int is_location(string location)
{
    if(AREALISTS_D->is_valid_location(location)) { return 1; }
    write("Note: capitalization is important.");
    return 0;
}

int header(string area,string what)
{
    write("\n%^BLUE%^==== %^RESET%^%^BOLD%^"+arrange_string(""+area+" "+what+"",24)+"%^RESET%^%^BLUE%^ ========================================%^RESET%^\n");
    return 1;
}

int footer()
{
    write("%^BLUE%^======================================================================%^RESET%^");
    return 1;
}

int display_list(string name,string *aliases,string adjective,int bounty,int fine)
{
    string aka="";
    int i;
    for(i=0;i<sizeof(aliases);i++)
    {
        aka += ""+capitalize(aliases[i])+", ";
    }
    write("  %^BOLD%^Real Name%^RESET%^:%^BLUE%^ "+arrange_string(capitalize(name),15)+"%^RESET%^%^BOLD%^Aliases%^RESET%^:%^BLUE%^ "+aka+"");
    write("  %^CYAN%^Adjective%^RESET%^: "+adjective+"");
    if(!bounty && !fine)     { write("\n"); }
    else if(bounty && fine)  { write("  %^RED%^Bounty%^RESET%^: "+arrange_string(bounty,18)+"%^GREEN%^Fine%^RESET%^: "+fine+"\n"); }
    else if(bounty && !fine) { write("  %^RED%^Bounty%^RESET%^: "+bounty+"\n"); }
    else if(!bounty && fine) { write("  %^GREEN%^Fine%^RESET%^: "+fine+"\n"); }
    return 1;
}

int help()
{
    write("  This command will display all information about all "
        "fines and bounties.  Examples of correct syntax follow.\n"
        "  %^BOLD%^arealist locations%^RESET%^ lists all valid locations.\n"
        "  %^BOLD%^arealist add jailer <town> <player name>%^RESET%^ will add \n"
        "     <player name> to the jailers list for <town>.\n"
        "  %^BOLD%^arealist add wanted <town> <player name>%^RESET%^ will add \n"
        "     <player name> to the wanted list for <town>.\n"
        "  %^BOLD%^arealist add bounty <town> <player name> <amount>%^RESET%^ will \n"
        "     place a bounty of <amount> on <player name> in <town>.\n"
        "  %^BOLD%^arealist add fine <town> <player name> <amount>%^RESET%^ will\n"
        "     fine <player name> <amount> in <town>.\n"
        "  %^BOLD%^arealist add alias <town> <type of list> <real name> <alias>%^RESET%^\n"
        "     will add <alias> as an alias of <real name> on <type of list>\n"
        "     (ie. wanted, jailers, fine, prisoners) in <town>.\n\n"
        "  %^BOLD%^arealist remove jailer <town> <player name>%^RESET%^ will \n"
        "     remove <player name> from the jailers list of <town>.\n"        
        "  %^BOLD%^arealist remove wanted <town> <player name>%^RESET%^ will \n"
        "     remove <player name> from wanted list in <town>.\n"
        "  %^BOLD%^arealist remove bounty <town> <player name>%^RESET%^ will \n"
        "     remove <player name>'s bounty in <town>.\n"
        "  %^BOLD%^arealist remove fine <town> <player name>%^RESET%^ will \n"
        "     remove <player name>'s fine in <town>.\n\n"
        "  %^BOLD%^arealist list jailers <town>%^RESET%^ will display a list \n"
        "     of all jailers for <town>.\n"
        "  %^BOLD%^arealist list prisoners <town>%^RESET%^ will display a list \n"
        "     of all prisoners currently in jail in <town>.\n"
        "  %^BOLD%^arealist list wanted <town>%^RESET%^ will display a list \n"
        "     of all people wanted in <town> along with bounty information.\n"
        "  %^BOLD%^arealist list fines <town>%^RESET%^ will display a list \n"
        "     of all people who have fines in <town> along with the amounts.\n");
    if(wizardp(TP))
    {
        write("  %^BOLD%^Additional information for wizards%^RESET%^:\n"
            "  %^BOLD%^arealist clean%^RESET%^ will cycle through all \n"
            "     of the valid areas and filter out invalid players, such \n"
            "     as those who have been time rid.  This command is process \n"
            "     hungry so use it sparingly.\n"
            "  %^BOLD%^arealist add <location>%^RESET%^ will add a new \n"
            "     valid location to the arealists.o mapping.\n"
            "  %^RED%^arealist remove <location>%^RESET%^ will remove a \n"
            "     location completely, including any information about fines, \n"
            "     bountites, jailers, etc.  Make sure the location is empty \n"
            "     before removing it, unless you are SURE you want to delete it.\n");
    }

    return 1;
}
        



    