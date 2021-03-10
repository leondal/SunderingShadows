#include "../../newbie.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("An imposing stone tower");
    set_short("%^MAGENTA%^An imposing stone tower");
    set_long("%^MAGENTA%^An imposing stone tower%^RESET%^\n"+
"This spacious room atop the stone tower is reserved for the protection of the local wizards' precious knowledge.  There "
"is a large ornate %^ORANGE%^desk %^RESET%^in one corner with a name plaque on it that reads 'Zabeth'.  Scrolls and books "
"in the process of being copied are spread around on the desk and nearby tables, obviously where mages or their "
"apprentices usually work.  %^CYAN%^Globes %^RESET%^of light hang over the work areas.  Scrolls are also neatly arranged "
"in several %^RED%^bookcases%^RESET%^, all securely protected behind doors of glass.  The walls are covered with "
"%^GREEN%^tapestries %^RESET%^picturing mages in study, and alchemists refining components.  A single window lies within "
"the stone %^ORANGE%^walls%^RESET%^, offering a view out over the town of Offestry.\n\n"
"%^YELLOW%^<help shop> %^RESET%^will give you help on how to use this shop.\n");
    set_smell("default","The tower smells of dry parchment, mingled with faint hints of sulfur.");
    set_listen("default","Little disturbs the quiet here.");
    set_items(([
        ({"wall","walls"}) : "%^ORANGE%^The walls are made of thick stone, probably to withstand the practicing of spells "
"that might go awry.  A few seem a little mis-aligned, though whether this is due to poor crafting or later impact "
"remains a mystery.  Regardless, the tower still seems quite sturdy.%^RESET%^",
        ({"globes","globe"}) : "%^CYAN%^The globes appear to be very delicate, etched from fine glass.  They have been "
"filled with phosphorescent moss that sheds a soft magical glow around the tower.%^RESET%^",
        ({"bookcases","bookcase"}) : "%^RED%^The bookcases have doors with glass to protect the scrolls from dust and "
"contamination, but still allow scanning of their labels on the ribbons that keep the scrolls rolled up.%^RESET%^",
        "desk" : "%^ORANGE%^The mahogany desk is ornately carved on all sides with scenes of dragons and other legendary "
"creatures.  The top is smooth and inlaid with ash and oak to form intricate starburst patterns.  The name plaque sitting "
"upon it reads 'Zabeth'.%^RESET%^",
        ({"tapestry","tapestries"}) : "%^GREEN%^One tapestry shows an elderly-looking alchemist working in a shop with "
"jars of various components all around.  Another shows a young mage studying various scrolls with a mentor and pointing "
"to sections with a questioning look.%^RESET%^",
    ]));
    set_exits(([
        "down" : MAINTOWN"mtower1",
    ]));
}

void reset(){
   ::reset();
   if(!present("zabeth")) find_object_or_load(MON"zabeth")->move(TO);
}