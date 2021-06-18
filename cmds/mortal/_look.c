//      /bin/user/_look.c
//      from the Nightmare mudlib
//      the command to look at stuff so that you might see!
//      written by Descartes of Borg 16 january 1993
//      based on the _look.c from the TMI mudlib

#include <daemons.h>

#include <std.h>

inherit DAEMON;

varargs int examine_object(string str,object obj);
void sky(string str);
varargs void look_msg(object ob, string str, object obj);


void db(string str)
{
    if(!TP->query_property("debug")) { return; }
    tell_object(TP,str);
    return;
}



int cmd_look(string str)
{
    string tmp,name,num;
    object obj;

    set_property("information",1);

    if(!objectp(TP)) { return 0; }

    if(str && str != "")
    {
        if( stringp(str) )
        {
            if(sscanf(str, "at %s on %s",tmp,name) == 2)
            {
                if(objectp(obj=present(name,environment(TP))))
                {
                    if(obj->query_property("shapeshifted"))
                    {
                        tell_object(TP,""+obj->QCN+" doesn't seem to have that.");
                        return 1;
                    }
                    return examine_object(tmp,obj);
                }
            }

            if(sscanf(str, "in %s", tmp) ==1 || sscanf(str, "at %s", tmp) == 1)
            {
                if((sscanf(tmp, "%s %d", name, num) == 2 && name == "player") || tmp == "player")
                {
                    return notify_fail("You do not notice that here.\n");
                }
                return examine_object(tmp);
            }
            else
            {
                if((sscanf(str, "%s %d", name, num) == 2 && name == "player") || str == "player")
                {
                    return notify_fail("You do not notice that here.\n");
                }//
                return examine_object(str);
            }
        }
    }
/*
        if(!((int)this_player()->query_invis()))
        tell_room(ETP,TPQCN+" looks at "+TP->query_possessive+" surroundings.");
*/
    TP->describe_current_room(1);
    return 1;
}


int check_shifted(object tp,object ob)
{
    if(!objectp(tp) || !objectp(ob)) { return 0; }

    if(tp->query_property("shapeshifted"))
    {
        if(ob->query_worn()) { return 0; }
        if(ob->query_wielded()) { return 0; }

        if(!FEATS_D->usable_feat(tp,"wild knowledge"))
        {
            if(base_name(ob) == "/d/azha/obj/gmr_ring") { return 1; }
            if(base_name(ob) == "/d/azha/obj/mr_ring") { return 1; }
            if(ob->id("kitxyz")) { return 1; }
            return 0;
        }
        return 1;
    }
    return 1;
}


varargs int examine_object(string str, object obj)
{
    object ob,wiz;
    object *obs, ob_list;
    int i;

    if(!str) { return 0; }

    if(TP->query_blind())
    {
        write("You are blind and cannot see anything.");
        return 1;
    }

    ob = environment(this_player());

    if(!wizardp(TP)&&(wiz=present(str,ob))&&wizardp(wiz)&&wiz->query_invis())
    {
        return notify_fail("You do not notice that here.\n");
    }

    if(TP->light_blind(0))
    {
        write(TP->light_blind_fail_message(TP->light_blind(1)));
        return 1;
    }

    if(total_light(this_player()) < 1)
    {
        write("It is dark.");
    }

    if(ob->id(str))
    {
        look_msg(ob, str);
        if(this_player()->query_ansi())
        {
            write(ansi_str( (string)ob->query_long(str) ));
        }
        else
        {
            write((string)ob->query_long(str));
        }
        return 1;
    }

    if(!objectp(obj))
    {
        ob = present(str, ob);
    }
    else
    {
        ob = present(str,obj);
    }

    if(ob)
    {
        if(((ob->query_hidden() && !TP->true_seeing())||
            (ob->query_magic_hidden() && !TP->detecting_invis())) &&
           ob != TP &&
           !avatarp(TP))
        {
            if(objectp(obj)) { return notify_fail(""+obj->QCN+" doesn't seem to have that."); }
            else { return notify_fail("You do not notice that here.\n"); }
        }

        look_msg(ob, str, obj);

        if(TP->query_ansi())
        {
            if(objectp(obj))
            {
                TP->more(ansi_str( (string)ob->query("long")));
            }
            else
            {
                //
                TP->more(ansi_str( (string)ob->query_long(str) ));
            }
        }
        else
        {
            if(objectp(obj))
            {
                TP->more(explode(ob->query("long"),"\n"));
            }
            else
            {
                //
                TP->more(explode(ob->query_long(str),"\n"));
            }
        }
        return 1;
    }

    ob = present(str, TP);

    if(ob)
    {
        if((ob->query_hidden() && !TP->true_seeing()) ||
           (ob->query_magic_hidden() && !TP->detecting_invis()))
        {
            return notify_fail("You do not notice that here.\n");
        }

        if(!check_shifted(TP,ob))
        {
            return notify_fail("You don't notice that here.\n");
        }

        look_msg(ob, str);

        if(this_player()->query_ansi())
        {
            write(ansi_str( (string)ob->query_long(str) ));
        }

        else
        {
            write((string)ob->query_long(str));
        }
        return 1;
    }

    write("You do not notice that here.");
    return 1;
}


varargs void look_msg(object ob, string str, object obj)
{
    if((int)this_player()->query_invis()) { return; }

    if( ob != this_player() )
    {
        if(objectp(ob))
        {
            if(living(obj))
            {
                if(ob->query_obvious_short()==0)
                {
                    tell_room(ETP,TPQCN+" looks at "+obj->QCN+"'s "+str+".",({obj,TP}));
                    tell_object(obj,TP->QCN+" looks over your "+str+".");
                    tell_object(TP,"You look over "+obj->QCN+"'s "+str+"");
                }
                else
                {
                    tell_room(ETP,TPQCN+" looks at "+obj->QCN+"'s "+ob->query_obvious_short()+".",({obj,TP}));
                    tell_object(obj,TP->QCN+" looks over your "+ob->query_obvious_short()+".");
                    tell_object(TP,"You look over "+obj->QCN+"'s "+str+"");
                }
                return;
            }

            if(living(ob))
            {
                tell_room(ETP,TPQCN+" looks over "+ob->query_cap_name()+ ".", ({ob,TP}));
                tell_object(ob, this_player()->query_cap_name() + " looks you over.");
                return;
            }
            if(ob->query_obvious_short()==0)
            {
                tell_room(ETP,""+TPQCN+" looks over the "+ str +".",TP);
            }
            else
            {
                tell_room(ETP,""+TPQCN+" looks over "+ ob->query_obvious_short() +".",TP);
            }
        }
    }
}



void sky(string str)
{
    string borg;
    int night, tmp;

    night = query_night();

    switch(str)
    {
        case "sky":

            if(night)
            {
                switch((int)EVENTS_D->query_week(time()))
                {
                    case 0:  borg = "You see a moonless night sky."; break;
                    case 1: borg = "The crescent moon hovers in the night sky."; break;
                    case 2: borg = "A full moon lights up the night sky."; break;
                    case 3: borg = "You see the sliver of a cresent moon in the sky."; break;
                    default: borg = "You see the edge of one moon and a second tiny satellite hovering in the sky."; break;
                }
            }
            else borg = "You see the sun up in the sky.";
            break;

        case "sun":

            if(!night)
            {
                tmp = (int)EVENTS_D->query_hour(time());
                if(tmp < 10) borg = "The sun hangs low in the eastern sky.";
                else if(tmp < 10) borg = "The sun is midway up in the eastern sky.";
                else if(tmp < 14) borg = "The sun is high up in the noon sky.";
                else if(tmp < 16) borg = "The sun is midway up in the western sky.";
                else borg = "The sun hangs low in the western sky.";
            }
            else borg = "What sun?";
            break;

        case "moon":

            switch((int)EVENTS_D->query_week(time()))
            {
                case 0: borg = "What moon?"; break;
                case 1: borg = "A crescent moon."; break;
                case 2: borg = "It is a full moon."; break;
                case 3: borg = "A tiny sliver of a crescent moon."; break;
                default: borg = "It looks like death!"; break;
            }
           break;

        case "moons":

            switch((int)EVENTS_D->query_week(time()))
            {
                case 0: borg = "What moons?"; break;
                default: return 0; break;
            }
    }

    write(borg);
    say(TPQCN+" looks at the "+str+".");
}

int help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

look - look at something

%^CYAN%^SYNOPSIS%^RESET%^

look %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [%^ORANGE%^%^ULINE%^NUMBER%^RESET%^]
look %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [%^ORANGE%^%^ULINE%^NUMBER%^RESET%^] on ground
look my %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [%^ORANGE%^%^ULINE%^NUMBER%^RESET%^]
look at %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [%^ORANGE%^%^ULINE%^NUMBER%^RESET%^] on %^ORANGE%^%^ULINE%^ENTITY%^RESET%^
look sky

%^CYAN%^DESCRIPTION%^RESET%^

If no %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ is specified this will show you the room you're in, otherwise it will return %^ORANGE%^%^ULINE%^OBJECT%^RESET%^'s long description.

To identify several similar objects you may append %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ to an object, e.g. %^ORANGE%^<look at my sack 2>%^RESET%^ will display description of second sack in your inventory.

If you specify keyword \"my\" you'll look only at objects in your inventory, e.g. %^ORANGE%^<look at my sack>%^RESET%^ will display description of sack in your inventory.

If you append suffix \"on ground\" you'll look only at objects on the ground.

You can look at %^ORANGE%^%^ULINE%^OBJECT%^RESET%^s on people and NPCs by specifying %^ORANGE%^%^ULINE%^ENTITY%^RESET%^ that possesses the %^ORANGE%^%^ULINE%^OBJECT%^RESET%^, e.g. %^ORANGE%^<look at sword on attacker>%^RESET%^ will display description of your attacker's sword.

Looking will notify everyone you're visible for about your action. To avoid this you might want to use %^ORANGE%^<glance>%^RESET%^.

There is a special object named sky you can look at and see various effects, depending on where an when you are.

%^CYAN%^SEE ALSO%^RESET%^

glance, peer, describe, set, terminal, brief
"
);
    return 1;
}
