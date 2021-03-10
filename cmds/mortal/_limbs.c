// Updating this to give more information so we can track what is worn on
// what limb -Ares
// Pator@ShadowGate
// Aug 21 1996
#include <std.h>

#define RACE_D "/adm/daemon/race_d.c"

int sort(string one,string two)
{
    string *order = ({ "right foot","right leg","left foot","left leg","right hand","right arm","left hand","left arm","waist","torso","neck","head"});
    int x,y;
    if(!stringp(one) && !stringp(two)) { return 0; }
    x = member_array(one,order);
    y = member_array(two,order);
    if(x > y)  { return -1; }
    if(x < y)  { return 1; }
    if(x == y) { return 0; }
}

int cmd_limbs(string str) 
{
    string *total_limbs,*current_limbs,*missing_limbs,*extra_limbs,*limbs,race,tmp;
    object *armors,targ;
    int i,j,limb_ac;

    if(!stringp(str)) { targ = TP; }
    if(!avatarp(TP)) { targ = TP; }
    if(!objectp(targ=find_player(str))) { targ = TP; }

    race = (string)targ->query_race();

    total_limbs   = RACE_D->query_limbs(race);
    total_limbs   += ({ "torso" });

    current_limbs = targ->query_limbs();

    if(sizeof(total_limbs) != sizeof(current_limbs))
    {
        missing_limbs = total_limbs - current_limbs;
        limbs = total_limbs;
        if(!sizeof(missing_limbs))
        {
            extra_limbs = current_limbs - total_limbs;
            limbs = total_limbs + extra_limbs;
        }
    }
    else
    {
        limbs = total_limbs;
    }

    if(sizeof(TP->query_fake_limbs())) { limbs = (string*)TP->query_fake_limbs(); }

    limbs = sort_array(limbs,"sort",TO);

    for(i=0;i<sizeof(limbs);i++)
    {
        if(sizeof(missing_limbs) && member_array(limbs[i],missing_limbs) != -1)
        {
            tell_object(TP,"  %^RESET%^%^RED%^"+limbs[i]+" %^RESET%^(%^RED%^not functional%^RESET%^)");
        }
        else if(sizeof(extra_limbs) && member_array(limbs[i],extra_limbs) != -1)
        {
            tell_object(TP,"  %^RESET%^%^YELLOW%^"+limbs[i]+" %^RESET%^(%^YELLOW%^extra limb%^RESET%^)");
        }
        else
        {
            tell_object(TP,"  %^RESET%^%^BOLD%^"+limbs[i]+"%^RESET%^");
        }

        armors = targ->query_armour(limbs[i]);
        if(sizeof(armors))
        {
            for(j=0;j<sizeof(armors);j++)
            {
                if(TP->query_property("shapeshifted")) { continue; }
                if(!objectp(armors[j])) { continue; }
                if(!avatarp(TP) && (string)armors[j]->query_short() == "") { continue; }
                if(avatarp(TP)) 
                {
                    if((int)armors[j]->query_ac() < 10)
                    {
                        tmp = arrange_string("    %^MAGENTA%^"+armors[j]->query_ac()+"%^RESET%^",6);
                    }
                    else
                    {
                        tmp = arrange_string("   %^MAGENTA%^"+armors[j]->query_ac()+"%^RESET%^",6);
                    }
                }
                else { tmp = "      "; }
                tmp += arrange_string(replace_string(armors[j]->query_short()," (worn)",""),45);
                tmp += "%^CYAN%^"+armors[j]->query_type()+"%^RESET%^";
                tell_object(TP,tmp);
            }
        }

    }
    return 1;
}

void help() 
{
    write(
        "
%^CYAN%^NAME%^RESET%^

limbs - list some limbs

%^CYAN%^DESCRIPTION%^RESET%^

This command will list the limbs that you currently have along with what you are wearing on that limb and the type of object that it is.  (armor, clothing, etc)

%^CYAN%^SEE ALSO%^RESET%^

corpselimbs, rend, eq, inv, look, glance, wield, wear, unwield, remove

"
          );
}


