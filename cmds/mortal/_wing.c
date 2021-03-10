#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <teleport.h>
inherit DAEMON;

#define WING_DELAY 120

string WINGO = "/cmds/mortal/obj/wingObj.c";

#include <common_destinations.h>

int cmd_wing(string args)
{
    object myshape, dest_room;
    string dest;

    if (TP->query_bound() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (TP->query_casting()) {
        tell_object(TP, "You're already casting a spell!");
        return 1;
    }

    if (!(RACE_D->can_fly(TP)||
          (TP->query_property("flying")))) {
        tell_object(TP, "You can not fly.");
        return 1;
    }

    if (TP->query_property("wing delay") + WING_DELAY > time()) {
        tell_object(TP, "Your wings are tired, you'll have to wait a bit.");
        return 1;
    }

    if (!(dest = TP->query_rem_room(args))) {
        if (member_array(args, keys(preset_destinations)) != -1) {
            dest = "" + preset_destinations[args];
            dest = (string)preset_destinations[args];
        }else {
            tell_object(TP, "You can't remember " + args + ".");
            return 1;
        }
    }

    if(!(dest_room = find_object("" + dest, 1)))
    {
        tell_object(this_player(), "Destination error. Contact an immortal.");
        return 1;
    }

    if (dest_room->query_property("indoors")) {
        tell_object(TP, "Your destination must be outside.");
        return 1;
    }

    if (ETP->query_property("indoors")) {
        tell_object(TP, "Your origin must be outside.");
        return 1;
    }

    if (!TELEPORT->object_can_be_teleported(TP, dest_room, TP->query_level(), 1)) {
        tell_object(TP, "Something prevents you from flying there.");
        return 1;
    }

    TP->remove_property("wing delay");
    TP->set_property("wing delay", time());
    tell_room(ETP, "%^BOLD%^%^WHITE%^" + TP->QCN + " flaps " + TP->QP + " wings and off " + TP->QS + " goes.%^RESET%^", TP);

    {
        object wing;
        wing = new(WINGO);
        wing->move(TP);
        wing->setup(TP, dest);
        call_other(dest_room, "???");
    }

    return 1;
}

void help()
{
    write(
        "%^CYAN%^NAME%^RESET%^

wing - spread your wings and fly away

%^CYAN%^SYNOPSIS%^RESET%^

wing %^ORANGE%^%^ULINE%^DESTINATION%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Wing allows you to move between locations, albeit much slower than teleportation. To use this command you must have wings sufficiently large enough to overcome winds (bird, bat, dragon, angelic aspect, fell flight, fey'ri, deva and others). This command will allow you to escape combat, but you can be intercepted during the flight.

You can travel to well known cities and destinations:
  Antioch
  Asgard
  Azha
  Deku
  Eldebaro
  Graez
  Juran
  Kinaro
  Muuldaan
  Lothwaite
  Nurval
  Seneca
  Shadow
  Tabor
  Tharis
  Tonovi
  Torm

Your memory has a higher priority in the case you want to overwrite any of these.

%^CYAN%^SEE ALSO%^RESET%^

remember, unremember, recall
");
}
