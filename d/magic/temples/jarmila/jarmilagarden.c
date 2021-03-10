//Temple of Jarmila - created by Nienne 1/18
//Garden added by Kismet.
// Proper path /d/magic/temples/jarmila/jarmilagarden.c
#include <std.h>
inherit "/std/templemisc";

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(0);
    set_temple("jarmila");
    set_name("The temple gardens");
    set_short("%^YELLOW%^The temple gardens%^RESET%^");
    set_long("%^YELLOW%^The temple gardens%^RESET%^\n"
             "%^BOLD%^%^WHITE%^You are on a small %^RESET%^flagstone path%^BOLD%^%^WHITE%^ that meanders through the garden that circles Jarmila's shrine.  A myriad of %^BOLD%^%^CYAN%^asters%^RESET%^%^BOLD%^%^WHITE%^, %^RESET%^%^RED%^roses%^RESET%^%^BOLD%^%^WHITE%^ and %^YELLOW%^daffodils%^RESET%^%^BOLD%^%^WHITE%^ grow along the path while further in rose bushes and magnolias rise against the backdrop of a %^RESET%^%^GREEN%^vine-covered%^BOLD%^%^WHITE%^ marble wall.  Behind the temple, you come upon a small and peaceful graveyard.  %^YELLOW%^Glowing %^RESET%^%^ORANGE%^sunstones%^RESET%^%^BOLD%^%^WHITE%^ lay at the head of each grave, which are lined with white stones and covered in blooming flowers.  A %^RESET%^%^RED%^ruby red rose brooch%^RESET%^%^BOLD%^%^WHITE%^ lays embedded in the center of one of the graves.  A stone bench meant for quiet contemplation stands along the temple wall, bearing a small golden plaque on its backrest.  Above the bench, the %^YELLOW%^holy symbol of Jarmila %^RESET%^%^BOLD%^%^WHITE%^has been carved into the wall, overlooking the graveyard. \n%^RESET%^");
    set_smell("default", "The sweet smell of flowers fills the air.");
    set_listen("default", "Gentle music drifts from somewhere in the temple.");
    set_items(([
                   ({ "sunstones", "sunstone" }) : "%^BOLD%^%^WHITE%^At the head of each grave, lays a glowing %^YELLOW%^sunstone%^RESET%^%^BOLD%^%^WHITE%^, upon which is written a name or a quote.  Upon two of the sunstones, are the names %^RESET%^'Selucia'%^BOLD%^%^WHITE%^ and %^RESET%^'Sir Arthus'%^BOLD%^%^WHITE%^.",
                   ({ "grave", "graves" }) : "%^BOLD%^%^WHITE%^The graves are all lined with white stones and covered with blooming flowers.  At the head of each grave, lays a glowing sunstone.%^RESET%^",
                   "brooch" : "%^BOLD%^%^WHITE%^A %^RESET%^%^RED%^ruby rose brooch%^RESET%^%^BOLD%^%^WHITE%^ bearing the holy symbol of Jarmila is embedded in the center of one grave.  The sunestone at the head of this grave reads  %^RESET%^'Selucia'%^BOLD%^%^WHITE%^.",
                   "bench" : "%^BOLD%^%^WHITE%^This stone bench rests against the temple wall and allows for quiet contemplation.%^RESET%^",
                   ({ "symbol", "symbol of jarmila", "symbol of Jarmila", "holy symbol of jarmila", "holy symbol of Jarmila" }) : "%^BOLD%^%^WHITE%^The holy symbol of Jarmila has been expertly carved into the wall: A crimson rose upon a shield of gold",
                   "plaque" : "%^BOLD%^%^WHITE%^The golden plaque upon the bench reads: %^YELLOW%^'In Reverie and Renewal'%^BOLD%^%^WHITE%^."
               ]));
    set_exits(([
                   "southwest" : "/d/magic/temples/jarmila/jarmilaentry", // change path to /d/magic/temples/jarmila/jarmilaentry.c
               ]));
}
