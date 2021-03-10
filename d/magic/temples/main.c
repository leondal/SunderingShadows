#include <std.h>

inherit ROOM;

#define TEMPLE "/d/magic/temples/"

void create(){
  ::create();
  set_light(2);
  set_indoors(1);
  set_property("no teleport",1);
  set_short("Portal of Temples");
  set_long(
@DESC
You are in a large room, so large that you cannot see from
one end to the other. All along the walls you see shimmering
portals, each with a name inscribed above. People are walking
in and out of the portals, so you see that it is safe to enter.
Looking closer, you see that there appears to be one portal
for each deity of the realm. 
DESC
  );
  set_exits(([
//    "out":"/d/shadow/room/city/church",
    "out":"/d/shadow/city/room/church",
    //"akadi":TEMPLE+"akadi",
    //"anhur":TEMPLE+"anhur",
    //"auril":TEMPLE+"auril",
    "auppenser":TEMPLE+"auppenser",
    //"bane":TEMPLE+"bane",
    "beshaba":TEMPLE+"beshaba",
    "callamir" : "/d/magic/temples/callamir/callamir.c",
    //"cyric":TEMPLE+"cyric",
    "eldath":TEMPLE+"eldath",
    "thefacelessone" : "/d/magic/temples/the_faceless_one/the_faceless_one.c",
    //"grumbar":TEMPLE+"grumbar",
    //"helm":TEMPLE+"helm",
    //"istishia":TEMPLE+"istishia",
    "jarmila" : "/d/magic/temples/jarmila/jarmila.c",
    "kismet" : "/d/magic/temples/kismet/kismet.c",
    "kelemvor":TEMPLE+"kelemvor",
    //"kossuth":TEMPLE+"kossuth",
    "krey" : "/d/magic/temples/kreysneothosies/kreysneothosies.c",
    //"lathander":TEMPLE+"lathander",
    "lordshadow" : "/d/magic/temples/lord_shadow/lord_shadow.c",
    //"loviatar":TEMPLE+"loviatar",
    "lysara" : "/d/magic/temples/lysara/lysara.c",
    //"malar":TEMPLE+"malar",
    //"mask":TEMPLE+"mask",
    "mielikki":TEMPLE+"mielikki",
    "mystra":TEMPLE+"mystra",
    "nilith" : "/d/magic/temples/nilith/nilith.c",
    "nim" : "/d/magic/temples/nimnavanon/nimnavanon.c",
    "oghma":TEMPLE+"oghma",
    "ryorik":"/d/magic/temples/ryorik/ryorik.c",
    "selune":TEMPLE+"selune",
    //"shar":TEMPLE+"shar",
    "shaundakul":TEMPLE+"shaundakul",
    "sune":TEMPLE+"sune",
    //"silvanus":TEMPLE+"silvanus",
    //"talos":TEMPLE+"talos",
    //"tempus":TEMPLE+"tempus",
    //"torm":TEMPLE+"torm",
    //"tymora":TEMPLE+"tymora",
    //"tyr":TEMPLE+"tyr",
    //"varda" : "/d/magic/temples/varda/varda.c",
    //"xvim":TEMPLE+"xvim"
  ]));
}
