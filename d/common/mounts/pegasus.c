//pegasus.c - For the holy avenger.  By Circe 9/5/04
#include <std.h>

inherit "/d/common/mounts/barded_flying_mount.c";

void create(){
    ::create();
    set_name("pegasus");
    set_short("beautiful winged pegasus");
    add_id("pegasus");
    add_id("winged pegasus");
    set_long("%^BOLD%^%^WHITE%^This breathtaking mount seems to be a "+
       "warhorse with delicate, feathery wings.  The horse is "+
       "barded in the manner of other warhorses, yet it does not "+
       "seem to hinder the creature in any way.  The pegasus's "+
       "mane is a %^YELLOW%^golden blonde %^WHITE%^that shimmers "+
       "in a light all its own, and its %^BLUE%^sapphire eyes "+
       "%^WHITE%^sparkle with an intelligence unmatched by any "+
       "mere beast.  From its stance, it is clear that this lovely "+
       "creature would allow only its chosen master to ride it."); 
   set_race("pegasus");
}