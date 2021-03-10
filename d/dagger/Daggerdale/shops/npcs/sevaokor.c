/*sevaokor.c - updated by Circe 11/4/03.  Added new description, changed race to human, changed inherit to NPC from comp_vendor*/
#include <std.h>
inherit NPC;

void create() {
    ::create();
    set_name("sevaokor");
    set_id( ({"sevaokor", "sheriff" }) );
    set_short("Sevaokor, the sheriff");
    set("aggressive", 0);
    set_level(15);
    set_long(
      "This weathered human male looks to be around forty years of age.  His dark "+
      "brown hair is spiced with silver, showing that time is creeping up on him.  "+
      "His face looks constantly to be in need of a shave, and some of the whiskers "+
      "have began to turn silver as well.  He is dressed in a comfortable pair of "+
      "leather pants and boots that look like they are almost as old as he is.  He "+
      "wears a leather jerkin with the image of a Roc resting on a pair of two "+
      "crossed daggers, the official symbol of Daggerdale.  An old pipe is planted "+
      "off to one side in his mouth."
    );
    set_languages( ({ "common" }) );
    set_gender("male");
    set_alignment(5);
    set_class("fighter");
    set_guild_level("fighter",15);
    set_race("human");
    set_hd(15,1);
    set_property("no bump", 1);
}

