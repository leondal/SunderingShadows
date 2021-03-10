/*
   common.c

   Written for the new guild Alliance Reborn.

   -- Tlaloc -- 3.24.20
 */

#include <std.h>

inherit VAULT;

void create()
{
    ::create();

    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_indoors(1);
    set_light(3);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_short("%^BOLD%^%^CYAN%^Quarters Common Area%^RESET%^");
    set_long("\n\
%^CYAN%^Quarters Common Area%^RESET%^\n" +
             "This is the common area for the various living quarters in the Alliance Reborn Keep. The area is very spacious and comfortable, and serves as a nice lounging area, with leather couches and cushioned chairs arranged around a beautiful stone fireplace. Above the fireplace is a beautiful painting depicting a group of heroes standing tall and shining in a background of darkness. On the fireplace mantle is a cigar box, for special occasions. On a small table in one of the corners is a magical decanter with a gentle amber liquid withing it and several cups arranged neatly.");
    set_exits(([
                   "east" : "/d/guilds/alliance/hall/hall",
                   "north" : "/d/guilds/alliance/hall/quartersnorth",
                   "west" : "/d/guilds/alliance/hall/quarterswest",
                   "south" : "/d/guilds/alliance/hall/quarterssouth",
               ]));

    set_door("yellow door", "/d/guilds/alliance/hall/quarterswest", "west");
    set_door("green door", "/d/guilds/alliance/hall/quartersnorth", "north");
    set_door("red door", "/d/guilds/alliance/hall/quarterssouth", "south");

    set_items(([
                   "painting" : "This painting is beautifully rendered. The scene that is depicted shows a backdrop of %^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^w%^BOLD%^i%^WHITE%^r%^BLACK%^ling b%^RESET%^%^MAGENTA%^l%^BOLD%^a%^WHITE%^c%^BLACK%^kness %^RESET%^and %^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^h%^BOLD%^a%^WHITE%^d%^BLACK%^ows %^RESET%^pressing in on all sides. In the foreground are a group of figures standing %^BOLD%^%^CYAN%^boldly %^RESET%^against the darkness around them. A %^BOLD%^%^MAGENTA%^half-elf %^RESET%^with %^BOLD%^%^CYAN%^indigo hair %^RESET%^and s%^BOLD%^t%^RESET%^eel-g%^BOLD%^r%^RESET%^ey e%^BOLD%^y%^RESET%^es powerfully strikes a shadowy figure reaching for a stalwart %^YELLOW%^deva %^RESET%^who is holding aloft an orb of %^YELLOW%^i%^WHITE%^n%^ORANGE%^c%^WHITE%^r%^ORANGE%^e%^WHITE%^d%^ORANGE%^i%^WHITE%^b%^ORANGE%^l%^WHITE%^e %^ORANGE%^b%^WHITE%^r%^ORANGE%^i%^WHITE%^g%^ORANGE%^h%^WHITE%^t%^ORANGE%^n%^WHITE%^e%^ORANGE%^s%^WHITE%^s %^RESET%^that seems to push the darkness towards the right side of the frame. Next to him is a %^BOLD%^pale%^RESET%^, %^GREEN%^hooded woman %^WHITE%^holding aloft a staff that emanates a %^BOLD%^%^GREEN%^veridian glow%^RESET%^, seeming to push away the shadows to the left side of the frame. Around the two are several figures: A %^GREEN%^s%^BOLD%^y%^RESET%^%^GREEN%^lvan e%^BOLD%^l%^RESET%^%^GREEN%^f %^WHITE%^with twirling blade fights off everal dark figures. A %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^awny e%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^f %^RESET%^with scores of %^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^tt%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^os %^RESET%^on his body glows with chaotic energy as his face twists in a feral rage. Between them stands a %^BOLD%^%^BLACK%^dark-haired%^RESET%^, %^BOLD%^%^MAGENTA%^a%^CYAN%^n%^MAGENTA%^d%^WHITE%^r%^MAGENTA%^o%^CYAN%^g%^MAGENTA%^y%^ORANGE%^n%^MAGENTA%^o%^CYAN%^u%^MAGENTA%^s %^RESET%^%^CYAN%^feytouched %^WHITE%^human who stabs one of the %^BOLD%^%^BLACK%^shadows %^RESET%^in the back as it attacks his companions. To the forefront another %^CYAN%^elf %^WHITE%^with %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ack %^RESET%^%^ORANGE%^hair %^WHITE%^and %^GREEN%^gr%^BOLD%^e%^BLACK%^e%^RESET%^%^GREEN%^n eyes %^WHITE%^stands protectively over two sleeping figures, with a blade in one hand and a %^YELLOW%^b%^WHITE%^l%^ORANGE%^i%^WHITE%^n%^ORANGE%^d%^WHITE%^i%^ORANGE%^n%^WHITE%^g %^ORANGE%^o%^WHITE%^r%^ORANGE%^b %^RESET%^of magic in the other hand. The sleeping figures he guards are of a %^BOLD%^%^BLACK%^rawboned %^RESET%^%^CYAN%^man %^WHITE%^in %^CYAN%^stylish clothes %^WHITE%^and a %^BOLD%^%^BLACK%^hooded %^RESET%^%^CYAN%^woman %^WHITE%^with %^ORANGE%^a%^RED%^u%^ORANGE%^burn h%^RED%^a%^ORANGE%^ir %^WHITE%^and a %^BOLD%^white robe. %^RESET%^The woman seems to have a %^YELLOW%^b%^WHITE%^r%^ORANGE%^i%^WHITE%^g%^ORANGE%^h%^WHITE%^t %^ORANGE%^b%^WHITE%^a%^ORANGE%^l%^WHITE%^l %^RESET%^of %^YELLOW%^e%^WHITE%^n%^ORANGE%^e%^WHITE%^r%^ORANGE%^g%^WHITE%^y %^RESET%^under her arm. In the center of the painting, standing behind and above the group with his arms stretched wide is a determined looking %^CYAN%^m%^BOLD%^%^WHITE%^o%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^-elf %^WHITE%^with %^RED%^r%^BOLD%^e%^RESET%^%^RED%^d h%^BOLD%^a%^RESET%^%^RED%^ir %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d%^BOLD%^-f%^RESET%^%^ORANGE%^l%^BOLD%^e%^RESET%^%^ORANGE%^c%^BOLD%^k%^RESET%^%^ORANGE%^e%^BOLD%^d %^BLUE%^blue eyes%^RESET%^. Around him is a torrent of energy that seems to protect the group and attack the darkness.",
                   "plaque" : "'In times they are needed\n\Such times they appear\n\When darkness has fallen\n\Heroes arise\n\And inspire the lost\n\Into glorious deeds\n\That would give them a name\n\That lives on to this day'",
               ]));
}
