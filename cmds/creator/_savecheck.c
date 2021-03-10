#include <std.h>





int cmd_savecheck(string str)
{
    object player;
    string *saves = ({ "fort","reflex","will" });
    string *temp,save;
    int mod,pass=0,fail=0,i;

    if(!stringp(str) || str == "" || str == " ") { return 0; }

    temp = explode(str, " ");

    if(sizeof(temp) != 3)
    {
        tell_object(TP,"Syntax: savecheck <player> <savetype> <mod>");
        return 1;
    }

    if(!objectp(player=find_player(temp[0])))
    {
        tell_object(TP,""+capitalize(str)+" doesn't appear to be online.");
        return 1;
    }

    if(member_array(save=temp[1],saves) == -1)
    {
        tell_object(TP,"You must pick either fort, reflex, or will as a saving throw.");
        return 1;
    }

    if(!intp(mod=to_int(temp[2])))
    {
        tell_object(TP,"You must enter a number for the modifier, negative numbers represent more difficult saves to pass.");
        return 1;
    }


    tell_object(TP,"Running save batch x 100.");
    tell_object(TP,"Save type: "+save+", save DC: "+absolute_value(mod)+"");

    
    switch(save)
    {
    case "fort":
        
        for(i=0;i<100;i++)
        {
            if("/daemon/saving_throw_d.c"->fort_save(player,mod)) { pass += 1; }
            else { fail += 1; }
        }

        break;

    case "reflex":

        for(i=0;i<100;i++)
        {
            if("/daemon/saving_throw_d.c"->reflex_save(player,mod)) { pass += 1; }
            else { fail += 1; }
        }

        break;

    case "will":

        for(i=0;i<100;i++)
        {
            if("/daemon/saving_throw_d.c"->will_save(player,mod)) { pass += 1; }
            else { fail += 1; }
        }

        break;
    }
    
    tell_object(TP,"Finished....");
    tell_object(TP,"Results:  Saves Passed = "+pass+", Saves Failed = "+fail+"");
    tell_object(TP,"Percentage passed = "+to_int((to_float(pass)/to_float(100))*100)+"%");
    return 1;

}
    

int help(string str)
{
    tell_object(TP,"Syntax: savecheck <player> <savetype> <mod>\n\n"
        "This command rolls a batch of saving throws of <savetype> using "
        "<player>'s saving throws.  It should give you an idea what the "
        "save DC needs to be at what level for a certain percentage "
        "chance to pass the saving throw.  Saves should have negative "
        "mods for DCs.");
    return 1;
}