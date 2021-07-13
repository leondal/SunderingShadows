//Base storage for tools merchants - Cythera 5/06
//added writing case ~Circe~ 6/15/07
#include <std.h>
#include "/d/common/common.h"

inherit ROOM;

void create()
{
    ::create();
    set_property("no teleport", 1);
    set_properties((["light" : 2, "indoors" : 1]));
    set_short("Common Tools Storage");
    set_long("Common Tools Storage. You probably shouldn't be here.");
    set_had_players(3);
}

void reset()
{
    ::reset();
    if (base_name(TO) == "/d/common/inherit/tools_storage") {
        return;
    }

    if (!present("armorsmithing tool set")) {
        new("/d/common/obj/misc/tools/armorsmithtoolset")->move(TO);
    }
    if (!present("small tool set")) {
        new("/d/common/obj/misc/tools/everythingtools")->move(TO);
    }
    if (!present("healer's kit")) {
        new("/d/common/obj/misc/tools/healerskit")->move(TO);
    }
    if (!present("jeweler's tools")) {
        new("/d/common/obj/misc/tools/jewellingkit")->move(TO);
    }
    if (!present("loupe")) {
        new("/d/common/obj/misc/tools/loupe")->move(TO);
    }
    if (!present("box")) {
        new("/d/common/obj/misc/tools/swordcare")->move(TO);
    }
    if (!present("weaponsmith tools")) {
        new("/d/common/obj/misc/tools/weaponsmithtoolset")->move(TO);
    }
    if (!present("artists kit")) {
        new("/d/common/obj/misc/tools/artistkit")->move(TO);
    }
    if (!present("kit of dyes")) {
        new("/d/common/obj/misc/tools/dyekit")->move(TO);
    }
    if (!present("skinning kit")) {
        new("/d/common/obj/misc/tools/skinningkit")->move(TO);
    }
    if (!present("writing case")) {
        new("/d/common/obj/misc/tools/writingcase")->move(TO);
    }

    //if (!present("portable lab case")) {
        //new("/d/common/obj/misc/tools/portable_lab_case")->move(TO);
    //}
    //if (!present("portable smithy bag")) {
        //new("/d/common/obj/misc/tools/portable_smithy_bag")->move(TO);
    //}
    //if (!present("portable scrying mirror")) {
       // new("/d/common/obj/misc/tools/portable_scrying_mirror")->move(TO);
    //}
    //if (!present("portable crystal ball")) {
        //new("/d/common/obj/misc/tools/portable_crystal_ball")->move(TO);
    //}

    switch (random(6)) {
    case 0:
        if (!present("quill")) {
            new("/d/common/obj/misc/tools/quill1")->move(TO);
        }
        if (!present("sewing kit")) {
            new("/d/common/obj/misc/tools/sewingkit")->move(TO);
        }
        if (!present("knife")) {
            new("/d/common/obj/misc/tools/skinningknife")->move(TO);
        }
        if (!present("hammer")) {
            new("/d/common/obj/misc/tools/smithyhammer1")->move(TO);
        }
        if (!present("forage kit")) {
            new("/d/common/obj/misc/tools/foragekit2")->move(TO);
        }
        break;

    case 1:
        if (!present("quill")) {
            new("/d/common/obj/misc/tools/quill2")->move(TO);
        }
        if (!present("sewing kit")) {
            new("/d/common/obj/misc/tools/sewingkit2")->move(TO);
        }
        if (!present("knife")) {
            new("/d/common/obj/misc/tools/skinningknife2")->move(TO);
        }
        if (!present("hammer")) {
            new("/d/common/obj/misc/tools/smithyhammer2")->move(TO);
        }
        if (!present("forage tool kit")) {
            new("/d/common/obj/misc/tools/foragekit")->move(TO);
        }
        break;

    case 2:
        if (!present("quill")) {
            new("/d/common/obj/misc/tools/quill3")->move(TO);
        }
        if (!present("sewing kit")) {
            new("/d/common/obj/misc/tools/sewingkit")->move(TO);
        }
        if (!present("knife")) {
            new("/d/common/obj/misc/tools/skinningknife3")->move(TO);
        }
        if (!present("hammer")) {
            new("/d/common/obj/misc/tools/smithyhammer3")->move(TO);
        }
        if (!present("forage kit")) {
            new("/d/common/obj/misc/tools/foragekit2")->move(TO);
        }
        break;

    case 3:
        if (!present("quill4")) {
            new("/d/common/obj/misc/tools/quill4")->move(TO);
        }
        if (!present("sewing kit")) {
            new("/d/common/obj/misc/tools/sewingkit2")->move(TO);
        }
        if (!present("knife")) {
            new("/d/common/obj/misc/tools/skinningknife4")->move(TO);
        }
        if (!present("hammer")) {
            new("/d/common/obj/misc/tools/smithyhammer3")->move(TO);
        }
        if (!present("forage tool kit")) {
            new("/d/common/obj/misc/tools/foragekit")->move(TO);
        }
        break;

    case 4:
        if (!present("quill")) {
            new("/d/common/obj/misc/tools/quill1")->move(TO);
        }
        if (!present("sewing kit")) {
            new("/d/common/obj/misc/tools/sewingkit")->move(TO);
        }
        if (!present("knife")) {
            new("/d/common/obj/misc/tools/skinningknife5")->move(TO);
        }
        if (!present("hammer")) {
            new("/d/common/obj/misc/tools/smithyhammer1")->move(TO);
        }
        if (!present("forage kit")) {
            new("/d/common/obj/misc/tools/foragekit2")->move(TO);
        }
        break;

    case 5:
        if (!present("quill")) {
            new("/d/common/obj/misc/tools/quill1")->move(TO);
        }
        if (!present("sewing kit")) {
            new("/d/common/obj/misc/tools/sewingkit2")->move(TO);
        }
        if (!present("knife")) {
            new("/d/common/obj/misc/tools/skinningknife")->move(TO);
        }
        if (!present("hammer")) {
            new("/d/common/obj/misc/tools/smithyhammer2")->move(TO);
        }
        if (!present("forage tool kit")) {
            new("/d/common/obj/misc/tools/foragekit")->move(TO);
        }
        break;
    }
}
