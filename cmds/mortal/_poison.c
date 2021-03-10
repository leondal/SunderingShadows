//Recoded by Saide to allow players to poison weapons, room doors, food, objects, etc. - Saide - April 3rd, 2013
/* poison.c
 * cmd to allow proficient players to poison their
 * weapons
 */

#include <std.h>
#include <daemons.h>
inherit DAEMON;

int help();

int cmd_poison(string str)
{
    string myVial, myTarg, DM, poison, pname, targShort;
    int doses, flag;
    mapping tmp_map;
    object PoisonVial, PoisonTarg;
    if(!objectp(TP)) return 0;
    if(!objectp(ETP)) return 0;
    if(!str) return help();
    if(sscanf(str, "%s with %s", myTarg, myVial))
    {
        if(!stringp(myTarg) || !stringp(myVial)) return help();
        if(!objectp(PoisonVial = present(myVial, TP)))
        {
            tell_object(TP, "You do not have "+myVial);
            return 1;
        }
        if(!PoisonVial->id("poison_vial_object_xxx"))
        {
            tell_object(TP, PoisonVial->query_short() + " is not a valid poison.");
            return 1;
        }
        if(!intp(doses = PoisonVial->query_poison_doses()))
        {
            tell_object(TP, "The vial of poison is empty!");
            return 1;
        }
        if(!doses)
        {
            tell_object(TP, "The vial of poison is empty!");
            return 1;
        }
        DM = PoisonVial->query_delivery_method();
        //we are only going to let injury type poison be applied to Objects
        if(!objectp(PoisonTarg = present(myTarg, TP)))
        {
            if(!objectp(PoisonTarg = present(myTarg, ETP)))
            {
                if(undefinedp(ETP->query_doors_map()))
                {
                    tell_object(TP, "You cannot find a "+myTarg+" to poison.");
                    return 1;
                }
                if(member_array(myTarg, keys(ETP->query_doors_map())) == -1)
                {
                    tell_object(TP, "You cannot find a "+myTarg+" to poison.");
                    return 1;
                }
                flag = 1;
            }
        }

        if(objectp(PoisonTarg))
        {
            pname = PoisonVial->query_poison_name();
            if(living(PoisonTarg))
            {
                tell_object(TP, "You cannot apply poison to a living creature.");
                return 1;
            }
            if(!PoisonTarg->is_food() && !PoisonTarg->is_drink())
            {
                if(DM == "ingested")
                {
                    tell_object(TP, "You cannot apply "+pname+ " to "+
                    PoisonTarg->query_short()+ ".");
                    return 1;
                }
            }

            doses--;


            targShort = PoisonTarg->query_short();
            TP->set_paralyzed(10, "%^BOLD%^%^RED%^You are busy applying poison!%^RESET%^");
            //10% chance of poisoning yourself when applying poison - Saide
            if(roll_dice(1,100) < 10)
            {
                tell_object(TP, "You make a costly mistake!");
                if(!TP->query_invis())
                {
                    tell_room(ETP, TPQCN +" seems to be applying something to "+targShort +
                    " and suddenly looks ill!", TP);
                }
                POISON_D->ApplyPoison(TP, pname, PoisonVial, DM);
                PoisonVial->set_poison_doses(doses);
                return 1;
            }
            PoisonVial->set_poison_doses(doses);
            if(POISON_D->is_poisoned(PoisonTarg))
            {

                tell_object(TP, "You begin to apply "+pname+
                " " + targShort +" and suddenly feel ill!");
                if(!TP->query_invis())
                {
                    tell_room(ETP, TPQCN +" seems to be applying something to "+targShort +
                    " and suddenly looks ill!", TP);
                }
                poison = PoisonTarg->query("PoisonType");

                POISON_D->is_object_poisoned(PoisonTarg, TP,
                POISON_D->query_poison_application_type(poison), 2);

                return 1;
            }
            tell_object(TP, "You quickly apply a coat of "+pname +
            " to "+targShort+".");
            if(!TP->query_invis())
            {
                tell_room(ETP, TPQCN +" seems to be applying something to "+myTarg, TP);
            }
            PoisonTarg->set("PoisonDoses", 1);
            PoisonTarg->set("PoisonType", pname);
            //a simple placeholder but should there exist such feats or abilities to make it so you are
            //immune to your own poisons put it here - Saide
            if(FEATS_D->usable_feat(TP,"perfect poisoner"))
            {
                PoisonTarg->set("whoImmune", TP->query_name());
            }
            return 1;
        }
        else
        {
            pname = PoisonVial->query_poison_name();
            if(DM != "contact")
            {
                tell_object(TP, "You cannot appy the "+pname+" to the "+myTarg);
                return 1;
            }


            doses--;

            TP->set_paralyzed(10, "%^BOLD%^%^RED%^You are busy applying poison!%^RESET%^");

            if(roll_dice(1,100) < 10 && !FEATS_D->usable_feat(TP, "perfect poisoner"))
            {
                tell_object(TP, "You make a costly mistake!");
                if(!TP->query_invis())
                {
                    tell_room(ETP, TPQCN +" seems to be applying something to "+myTarg +
                    " and suddenly looks ill!", TP);
                }
                POISON_D->ApplyPoison(TP, pname, PoisonVial, DM);
                PoisonVial->set_poison_doses(doses);
                return 1;
            }
            PoisonVial->set_poison_doses(doses);
            tmp_map = ETP->query("PoisonInfo");

            if(POISON_D->is_poisoned(ETP, myTarg))
            {
                tell_object(TP, "You begin to apply "+pname+ " to the "+
                myTarg+" and suddenly feel ill!");
                if(!TP->query_invis())
                {
                    tell_room(ETP, TPQCN +" seems to be applying something to "+myTarg +
                    " and suddenly looks ill!", TP);
                }
                tmp_map = ETP->query("PoisonInfo");
                poison = tmp_map[myTarg]["PoisonType"];

                POISON_D->is_object_poisoned(ETP, TP, POISON_D->query_poison_application_type(poison), 2, myTarg);

                return 1;
            }
            if(!mapp(tmp_map))
            {
                if(FEATS_D->usable_feat(TP,"perfect poisoner"))
                {
                    tmp_map = ([myTarg : (["PoisonType" : pname, "PoisonDoses" : 1, "whoImmune" : TP->query_name()]) ]);
                }
                else tmp_map = ([myTarg : (["PoisonType" : pname, "PoisonDoses" : 1]) ]);
            }
            else
            {
                if(FEATS_D->usable_feat(TP,"perfect poisoner"))
                {
                    tmp_map += ([myTarg : (["PoisonType" : pname, "PoisonDoses" : 1, "whoImmune" : TP->query_name()]) ]);
                }
                else  tmp_map += ([myTarg : (["PoisonType" : pname, "PoisonDoses" : 1]) ]);
            }

            tell_object(TP, "You quickly apply a coat of "+pname +
            " to "+myTarg+".");
            if(!TP->query_invis())
            {
                tell_room(ETP, TPQCN +" seems to be applying something to "+myTarg, TP);
            }
            ETP->set("PoisonInfo", tmp_map);
            return 1;
        }
    }
    return help();
}

int help()
{
  write(
"
%^CYAN%^NAME%^RESET%^

poison - add poison to objects

%^CYAN%^SYNOPSIS%^RESET%^

poison OBJECT with POISON

%^CYAN%^DESCRIPTION%^RESET%^

This command allows you to attempt to poison an object, should you have the needed vial of poison. There are different types of poison which can be applied to different objects. Valid objects should be any item that you possess or any door in a room.

There are three types of poisons. They are contact, ingested, and injury. Contact poisons can be applied to doors or objects, including weapons. They will poison who ever next comes into contact with them. Ingested poisons can be applied to food or drink. Injury poisons can be applied to weapons to affect whoever you hit with the weapon in combat.

There is a risk associated with applying a poison and a certain risk with fighting with a poisoned weapon.

%^CYAN%^SEE ALSO%^RESET%^

spy, steal, sign, thief, poison *spells
"        );
  return 1;
}
