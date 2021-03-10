//Adapted from rope trick room by
//~Circe~ for use with psions 7/20/05
//ganked for the sanctify cleric spell -Ares
#include <std.h>
#include <magic.h>

void set_desc(string diety);

inherit ROOM;

object entry, rope;
string roomName, * desc = ({});

void create()
{
    ::create();
    set_light(1);
    set_property("no teleport", 1);
    set_property("no sticks", 1);
    set_property("indoors", 1);
    set_terrain(CITY);
    set_travel(STAIRWAY);
}

void init()
{
    ::init();
    add_action("pull_up_rope", "close");
    add_action("lower_rope", "open");
}

void set_entry(object ob, object rp, string where)
{
    entry = ob;
    rope = rp;
    roomName = where;
}

int pull_up_rope(string str)
{
    object* inv;
    int x, people;

    if (str != "gate") {
        return 0;
    }
    if (this_player()->query_bound() != 0)
        return 0;
    inv = all_inventory(TO);
    for (x = 0; x < sizeof(inv); x++) {
        if (living(inv[x])) {
            people = people + 1;
        }
    }
    if (people > 7) {
        tell_object(TP, "The demiplane is not large enough to close the gate with " +
                    "more than eight people in the space.");
        return 1;
    }
    tell_room(TO, TPQCN + " secures the gate, making this demiplane " +
              "inaccessible from outside!", TP);
    tell_object(TP, "You secure the gate, making this demiplane " +
                "inaccessible from outside.");
    rope->raise();
    TO->remove_exit("out");
    return 1;
}

int lower_rope(string str)
{
    if (str != "gate") {
        return 0;
    }
    if (this_player()->query_bound() != 0)
        return 0;
    tell_room(TO, TPQCN + " opens the gate, granting access to " +
              "the Prime Material plane.", TP);
    tell_object(TP, "You open the gate to the Prime Material plane.");
    rope->lower();
    if (!objectp(entry)) {
        entry = find_object_or_load(roomName);
    }
    TO->add_exit(base_name(entry), "out");
    return 1;
}

void destroy_space()
{
    object* inv;
    int x;

    inv = all_inventory(TO);
    if (!objectp(entry)) {
        entry = find_object_or_load(roomName);
    }
    for (x = 0; x < sizeof(inv); x++) {
        inv[x]->move(entry);
    }
    if (sizeof(inv)) {
        tell_room(entry, wrap("You see something appear out of thin air!\n"));
    }
    "/daemon/virtual_room_d.c"->destroy_virtual_room(TO->query("my_virtual_name"), entry);
    TO->remove();
}

void set_desc(string diety)
{
    switch (diety) {
    case "callamir":
        desc += ({ "%^BLUE%^A circular shrine" });
        desc += ({ "%^BLUE%^Crafted of a %^BOLD%^blue%^RESET%^%^BLUE%^ veined marble, this circular" +
                   " shrine features a gilded %^BOLD%^%^WHITE%^silver%^RESET%^%^BLUE%^ dome.  Marble " +
                   "columns line the outer perimeter of the shine, giving an unimpeded view of the " +
                   "deep blue sky.  Carved into the columns are images of people testing their luck," +
                   " from games of chance, to more daring displays of skill. Glancing at the surrounding" +
                   " landscape, it seems as if this shrine was built on a rolling hill of " +
                   "%^BOLD%^%^GREEN%^shamrocks%^RESET%^%^BLUE%^.  A circular rug woven of %^BOLD%^blue" +
                   "%^RESET%^%^BLUE%^ and %^RESET%^silver%^BLUE%^ fibers covers the floor of the shrine." +
                   "  Images of rabbits, foxes and silver sparrows are depicted in the rug.  " +
                   "Hovering in the center of the shrine is a %^BOLD%^%^WHITE%^silver%^RESET%^%^BLUE%^" +
                   " sphere.  As the sphere turns chaotically, a bright glow radiates from it, filling" +
                   " the shrine with light.  Hanging in the air is a feeling of good fortune and merriment." });
        break;

    case "jarmila":
        desc += ({ "%^BOLD%^%^GREEN%^A field at dawn" });
        desc += ({ "%^BOLD%^%^GREEN%^New plants thrive in this field, growing with" +
                   " the blessings of the spring.  Though the plants are small right now," +
                   " they speak of a promise of growing into something larger, brimming " +
                   "with vitality.  %^BOLD%^%^MAGENTA%^Asters%^GREEN%^ and %^RED%^r%^RESET%^" +
                   "%^RED%^o%^BOLD%^%^RED%^s%^RESET%^%^RED%^e%^BOLD%^%^RED%^s%^GREEN%^ can be found " +
                   "scattered around the field.  A clear sky overhead gives an unimpeded view all " +
                   "the way to the horizon.  The sky is bathed in the colors of the" +
                   " %^RESET%^%^RED%^d%^BOLD%^a%^RESET%^%^ORANGE%^w%^BOLD%^%^MAGENTA%^n%^GREEN%^, " +
                   "bringing with it the promise of a %^YELLOW%^new day%^GREEN%^ and a" +
                   " %^BOLD%^%^MAGENTA%^new beginning%^GREEN%^.  Everything " +
                   "about this field speaks of life, beauty, and rebirth." });
        break;

    case "kismet":
        desc += ({ "%^ORANGE%^An ornate library" });
        desc += ({ "%^ORANGE%^The interior of this space is tastefully, but lavishly" +
                   " decorated.  Lining several walls of the room are %^MAGENTA%^bookshelves" +
                   "%^ORANGE%^ filled with tomes, scrolls and books on a variety of subjects." +
                   "  Overhead an ornate %^BOLD%^%^WHITE%^crystalline%^RESET%^%^ORANGE%^ chandelier " +
                   "hangs, casting pale rainbows across the walls.  Instruments from various " +
                   "cultures and regions are proudly mounted onto another wall, above glass cases " +
                   "filled with miraculously engineered contraptions of unknown intent, and " +
                   "masterfully crafted works of all kinds.  The wooden floor is " +
                   "covered by a %^RESET%^pale%^ORANGE%^ rug, richly woven to " +
                   "depict images of minstrels, singers, troubadours, and bards of all races" +
                   " and genders.  Ornately carved chairs padded with" +
                   " %^BOLD%^%^WHITE%^snowy silk%^RESET%^%^ORANGE%^ flank the room.  The cushions" +
                   " of the chairs are embroidered in a myriad of hues, depicting various" +
                   " runes, glyphs and symbols of power through the ages.  An inspiring wordless" +
                   " melody fills the air, blended harmoniously with the distant trill of songbirds." });
        break;

    case "kreysneothosies":
        desc += ({ "%^BOLD%^%^WHITE%^A white citadel" });
        desc += ({ "%^BOLD%^%^BLUE%^Standing in the centre of a wide and verdant plain, this citadel offers an impressive " +
                   "view of the surrounding area.  Fashioned out of %^BOLD%^%^WHITE%^white%^BLUE%^" +
                   " granite, the walls of this fortress glow with a pure %^YELLOW%^light%^BLUE%^.  " +
                   "Within the chamber itself, the decorations are elegant but utilitarian in style.  Lining the" +
                   " walls are statues of regal %^YELLOW%^golden dragons%^BLUE%^ and noble %^WHITE%^armored" +
                   " knights%^BLUE%^.  In the center of the room a carved wooden table lays, with benches" +
                   " flanking either side.  Outside, tall spires rise to either side of the building, high above the rounded " +
                   "roof which is shaped in typically Tsarven style.  Far below, beneath their protective shadows, rise the " +
                   "yield of a %^GREEN%^fertile farmland %^BLUE%^- ears of grain, and ripe fruits ready to be picked.  A feeling of order and " +
                   "responsibility fills the air." });
        break;

    case "lord shadow":
        desc += ({ "%^BOLD%^%^CYAN%^An ornate throne room" });
        desc += ({ "%^RESET%^%^BLUE%^The high vaulted ceilings of this room are cloaked" +
                   " in %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^.  The ornate room is decorated with carvings of " +
                   "%^RESET%^%^GREEN%^gargoyles%^BLUE%^ and %^RED%^devils%^BLUE%^" +
                   ", looking fearsome and intimidating.  The" +
                   " %^BOLD%^%^BLACK%^black%^RESET%^%^BLUE%^ obsidian floor is veined with " +
                   "%^BOLD%^%^CYAN%^azure%^RESET%^%^BLUE%^, and polished" +
                   " to a high shine.  %^BOLD%^%^WHITE%^F%^BOLD%^%^CYAN%^ro%^BOLD%^%^WHITE%^s" +
                   "%^BOLD%^%^CYAN%^tf%^BOLD%^%^WHITE%^y%^BOLD%^%^CYAN%^re %^RESET%^%^BLUE%^flames " +
                   "dance in a brazier, scattering eerily moving patterns across the walls.  " +
                   "Running through the center of the room is a " +
                   "richly decorated wool rug, embellished with precious metals.  " +
                   "The rug leads to a high dais where a massive %^BOLD%^%^BLACK%^black " +
                   "obsidian throne%^RESET%^%^BLUE%^ dominates the room.  Behind the throne, towering " +
                   "above all else, is a tapestry of a shadowed man with %^BOLD%^%^BLACK%^ink-black " +
                   "eyes%^RESET%^%^BLUE%^, his open hand raised in a gesture of command.  All around this room a "
                   "feeling of %^RED%^dominance%^RESET%^%^BLUE%^ and" +
                   " %^BOLD%^%^BLACK%^fear%^RESET%^%^BLUE%^ flows." });
        break;

    case "lysara":
        desc += ({ "%^BOLD%^A moon bathed valley" });
        desc += ({ "%^CYAN%^Nestled between three mountains lays this valley.  The tall " +
                   "grass dances in the gentle breeze that billows in.  %^GREEN%^Vines" +
                   " %^CYAN%^wrap around the ancient trees, reaching up towards the heavens." +
                   "  In the clear %^BLUE%^dark blue%^CYAN%^ sky above, the multitude of " +
                   "%^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^s%^RESET%^%^CYAN%^" +
                   " glitter like diamonds.  The %^BOLD%^%^WHITE%^full moon%^RESET%^%^CYAN%^ " +
                   "above holds court over the valley, bathing everything in a serene " +
                   "%^RESET%^silvery %^CYAN%^radiance.  At the centre of the valley stands " +
                   "a small and simple mausoleum of %^RESET%^gray %^CYAN%^marble, a somber " +
                   "reminder that none can escape their fate predestined by the Lady of the Dead.  " +
                   "Waves from the nearby %^BLUE%^pond %^CYAN%^lap against the shore like a calm, unwavering " +
                   "heartbeat.  A feeling of serenity and tranquility flows through the shrine." });
        break;

    case "nimnavanon":
        desc += ({ "%^GREEN%^An autumn grove" });
        desc += ({ "%^GREEN%^Ancient trees cluster around this remote grove, lending a " +
                   "feeling of solitude and privacy.  %^YELLOW%^Sunlight%^RESET%^%^GREEN%^" +
                   " streams through the branches of the towering sentinels.  A " +
                   "multitude of trees are represented here, from %^ORANGE%^oaks" +
                   "%^GREEN%^ to %^RED%^sequoias%^GREEN%^, to even more exotic " +
                   "varieties such as %^BLUE%^shadowtop%^GREEN%^ and %^CYAN%^cypress" +
                   "%^GREEN%^.  They all share one common bond, their leaves " +
                   "displaying the colors of %^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^u" +
                   "%^YELLOW%^t%^RED%^u%^RESET%^%^ORANGE%^m%^YELLOW%^n%^RESET%^%^GREEN%^." +
                   "  %^BOLD%^%^RED%^Reds%^RESET%^%^GREEN%^, %^YELLOW%^golds%^RESET%^%^GREEN%^, " +
                   "%^ORANGE%^oranges%^GREEN%^, and greens create a colorful pattern around the grove.  " +
                   "Everything about this grove speaks of pure nature and vitality." });
        break;

    case "the faceless one":
        desc += ({ "%^BOLD%^%^BLACK%^A dark room%^RESET%^" });
        desc += ({ "%^BLUE%^Removed from the world, this rectangular shaped room " +
                   "is cloaked in %^BOLD%^%^BLACK%^shadows%^RESET%^%^BLUE%^.  Sconces " +
                   "made from the %^BOLD%^%^WHITE%^skulls%^RESET%^%^BLUE%^ of humanoid" +
                   " and monstrous creatures add some light to the space.  An ever " +
                   "changing %^MAGENTA%^m%^CYAN%^i%^RESET%^s%^GREEN%^t%^BLUE%^ snakes " +
                   "through the room, adding to the feeling of secrecy and deception " +
                   "that the shadows create.  Chairs made of %^BOLD%^%^WHITE%^bone" +
                   "%^RESET%^%^BLUE%^ are set around the edges of the room, in a variety of designs" +
                   " and heights.  %^BOLD%^%^BLACK%^Gray%^RESET%^%^BLUE%^ velvet marked " +
                   "with scattered %^BOLD%^%^RED%^teardrop%^RESET%^%^BLUE%^ patterns pads " +
                   "the floor of this room, silencing any sounds.  In the air a feeling of " +
                   "deception and intrigue hangs." });
        break;

    case "varda": //was varda
        desc += ({ "%^RED%^An ancient shrine" });
        desc += ({ "%^RED%^Crafted from %^RESET%^granite%^RED%^, this ancient shrine appears worn" +
                   " and well used.  In the center of the room a gigantic %^BOLD%^%^BLACK%^metal" +
                   "%^RESET%^%^RED%^ bowl has been affixed to the ground.  Hovering in the air above" +
                   " the bowl is a massive iron battle axe, and as it rotates over the bowl," +
                   " droplets of %^BOLD%^blood%^RESET%^%^RED%^ fall from its sharpened edge." +
                   "  %^ORANGE%^Maps%^RED%^ of ancient battles cover the wall to the shrine, relics from" +
                   " wars long gone.  Statues of strong martial warriors line the shrine, some clothed" +
                   " in nothing more than scraps of fur and wielding immense axes, while others wear worn " +
                   "suits of platemail and wield swords. A variety of races, cultures, and kingdoms" +
                   " can be found represented amongst in the statues.  %^BOLD%^%^WHITE%^Banners%^RESET%^%^RED%^ taken from" +
                   " historic battles hang from the rafters, some worn, tattered, and bloody.  A martial " +
                   "feeling fills the halls of this shrine." });
        break;

    case "nilith":
        desc += ({ "%^BOLD%^%^MAGENTA%^A %^RESET%^%^MAGENTA%^M%^BOLD%^%^GREEN%^a%^BLACK%^ca%^GREEN%^b%^RESET%^%^MAGENTA%^r%^BOLD%^e %^RESET%^%^MAGENTA%^G%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^a%^BOLD%^%^MAGENTA%^v%^RESET%^%^GREEN%^e%^MAGENTA%^y%^GREEN%^a%^BOLD%^r%^RESET%^%^MAGENTA%^d%^WHITE%^" });
        desc += ({ "%^BOLD%^%^BLACK%^You stand in the middle of a %^RESET%^%^MAGENTA%^m%^BOLD%^%^GREEN%^a%^BLACK%^ca%^GREEN%^b%^RESET%^%^MAGENTA%^r%^BOLD%^e %^RESET%^%^MAGENTA%^g%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^a%^BOLD%^%^MAGENTA%^v%^RESET%^%^GREEN%^e%^MAGENTA%^y%^GREEN%^a%^BOLD%^r%^RESET%^%^MAGENTA%^d %^BOLD%^%^BLACK%^lit only by the faintest flicker of %^RESET%^%^CYAN%^m%^BOLD%^o%^WHITE%^o%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^l%^CYAN%^i%^WHITE%^g%^RESET%^%^CYAN%^h%^BOLD%^t%^BLACK%^. Shambling undead in various stages of %^RESET%^%^RED%^d%^ORANGE%^e%^GREEN%^ca%^ORANGE%^y %^BOLD%^%^BLACK%^stagger around, waiting on their master's call. A thick, rolling %^RESET%^f%^BOLD%^%^BLACK%^o%^RESET%^g %^BOLD%^%^BLACK%^blankets the area. The air is unnaturally %^CYAN%^s%^RESET%^%^BLUE%^ti%^BOLD%^%^CYAN%^l%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^, with only the soft moans of the undead floating through the air.%^RESET%^" });
        break;

    case "seija":
        desc += ({ "%^BOLD%^%^CYAN%^A %^GREEN%^P%^MAGENTA%^e%^CYAN%^a%^GREEN%^c%^CYAN%^e%^MAGENTA%^f%^GREEN%^u%^CYAN%^l %^ORANGE%^R%^RESET%^%^ORANGE%^oc%^BOLD%^k %^GREEN%^G%^RESET%^%^GREEN%^a%^BOLD%^r%^RESET%^%^GREEN%^d%^BOLD%^en%^RESET%^" });
        desc += ({ "%^BOLD%^%^CYAN%^You find yourself in the middle of a painstakingly maintained %^ORANGE%^r%^RESET%^%^ORANGE%^oc%^BOLD%^k %^CYAN%^and %^RESET%^%^ORANGE%^s%^BOLD%^a%^RESET%^%^ORANGE%^n%^BOLD%^d %^GREEN%^g%^RESET%^%^GREEN%^a%^BOLD%^r%^RESET%^%^GREEN%^d%^BOLD%^en%^CYAN%^, surrounding a small %^MAGENTA%^l%^WHITE%^i%^MAGENTA%^l%^WHITE%^y %^CYAN%^pond. A small bridge crosses the pond, and %^RED%^k%^ORANGE%^o%^WHITE%^i %^CYAN%^fish periodically nudge the surface of the p%^RESET%^%^CYAN%^o%^BOLD%^n%^RESET%^%^CYAN%^d%^BOLD%^, looking for food. %^MAGENTA%^L%^WHITE%^i%^MAGENTA%^l%^WHITE%^ie%^MAGENTA%^s %^CYAN%^float lazily on the surface. A %^RESET%^%^ORANGE%^rake %^BOLD%^%^CYAN%^is stationed on the side of the bridge, for use in drawing in the sand.%^RESET%^" });
        break;

    case "khyron":
        desc += ({ "%^BOLD%^%^BLUE%^The %^MAGENTA%^E%^RESET%^%^MAGENTA%^y%^BOLD%^e %^BLUE%^of a %^ORANGE%^H%^RESET%^%^CYAN%^u%^BOLD%^rr%^RESET%^i%^YELLOW%^c%^BLUE%^a%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^e%^RESET%^" });
        desc += ({ "%^BOLD%^%^BLUE%^You stand in the eye of a %^ORANGE%^s%^RESET%^%^ORANGE%^w%^BOLD%^%^BLUE%^i%^ORANGE%^r%^RESET%^%^BLUE%^l%^BOLD%^in%^RESET%^%^ORANGE%^g %^BOLD%^h%^RESET%^%^CYAN%^u%^BOLD%^rr%^WHITE%^i%^ORANGE%^c%^BLUE%^a%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^e. While at the center, the air is calm, you can see destruction swirling around you. %^ORANGE%^L%^WHITE%^i%^ORANGE%^g%^WHITE%^h%^ORANGE%^t%^WHITE%^n%^ORANGE%^i%^WHITE%^n%^ORANGE%^g %^BLUE%^flashes and %^RESET%^%^ORANGE%^t%^WHITE%^h%^ORANGE%^u%^WHITE%^n%^ORANGE%^d%^WHITE%^e%^ORANGE%^r %^BOLD%^%^BLUE%^shakes your very %^RESET%^b%^BOLD%^o%^RESET%^n%^BOLD%^es%^BLUE%^. The gale-force winds roar, tearing up the earth around your %^GREEN%^p%^RESET%^%^GREEN%^e%^BOLD%^%^MAGENTA%^a%^GREEN%^c%^MAGENTA%^e%^GREEN%^fu%^RESET%^%^GREEN%^l %^BOLD%^%^BLUE%^center.%^RESET%^" });
        break;

    case "cevahir":
        desc += ({ "%^RESET%^%^ORANGE%^A well-outfitted war room%^RESET%^" });
        desc += ({ "%^RESET%^%^ORANGE%^This %^BOLD%^oak-paneled %^RESET%^%^ORANGE%^room seems to be far removed from the rest of the world, despite the %^CYAN%^windows %^ORANGE%^on three of the four sides looking out upon scenes of %^RED%^battle%^ORANGE%^. The %^RESET%^stone floor %^ORANGE%^has been covered with thick %^MAGENTA%^pa%^BOLD%^t%^RESET%^%^MAGENTA%^te%^RESET%^r%^MAGENTA%^ned rugs%^ORANGE%^, and a %^RED%^f%^BOLD%^i%^YELLOW%^r%^RESET%^%^RED%^e %^ORANGE%^crackles in the %^RESET%^stone fireplace %^ORANGE%^set within the fourth wall. Arranged around the room are %^YELLOW%^tables %^RESET%^%^ORANGE%^covered in %^RESET%^maps %^ORANGE%^and lined with stools and benches enough to accommodate many people as they planned. Baskets near the fireplace hold pieces for strategy games, and the space is thick with an atmosphere of planning.%^RESET%^" });
        break;

    default:
        desc += ({ "%^GREEN%^A humble shrine" });
        desc += ({ "%^GREEN%^Set apart from the rest of the world, this humble shrine is composed" +
                   " of dull gray marble.  The featureless shrine is left bare, appearing as if it " +
                   "has been abandoned.  Ivy snakes up one of the walls, reaching for the ceiling." +
                   "  Patches of moss can be found on the stone floor, adding to the deserted feeling." +
                   "  Open portals provide a glimpse of the landscape outside.  Tall grass working with" +
                   " the thick forest work to nearly conceal this shrine from the rest of the world." });
        break;
    }

    desc +=
        ({ "\n\n%^RESET%^close gate:     This closes the gate to the Prime \n"
           "                Material plane, blocking anyone else from entering.\n\n"

           "open gate:      This reconnects the demiplane with the Prime \n"
           "                Material plane, allowing people to enter or leave.\n\n"

           "out:            This is the exit to the Prime Material plane, \n"
           "                so long as the gate is open.\n\n"

           "WARNING to all inhabitants of this space!!  You may NOT use a rope "
           "trick spell or genesis power or sanctify spell within this space.  "
           "Also, at the end of the spell's duration, everything in this space "
           "will be ejected into the Prime Material plane, including you.  Be warned!" });

    TO->set_short(desc[0]);
    TO->set_long(desc[1] + desc[2]);
    return;
}
