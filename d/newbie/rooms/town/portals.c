#include <std.h>
#include "../../newbie.h"
inherit ROOM;

void create(){
  ::create();
  set_light(2);
  set_indoors(1);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_name("Shrine of the Gods");
  set_short("%^YELLOW%^Shrine of the Gods");
  set_long("%^YELLOW%^Shrine of the Gods%^RESET%^\n"
"This sizeable %^CYAN%^shrine %^RESET%^is almost a room unto itself, but the way "
"it lies half-open onto the church nave makes it still feel part of that larger "
"chamber.  Roughly square in layout, its plain walls contain several %^MAGENTA%^alcoves "
"%^RESET%^upon each face, allowing for ten in total.  Each is small, but carefully "
"decorated, should you wish to %^YELLOW%^look %^RESET%^at them more closely.\n");
  set_smell("default","The fragrance of many types of incense lingers here.");
  set_listen("default","You can hear various chants and conversations coming through the different portals.");
  set_exits(([
    "south":MAINTOWN"church",
  ]));
  set_items(([
//add Nilith and Ryorik, remove Varda
    ({"alcoves","shrines"}):"There are ten alcoves around the room, each wall supporting three at "
"equidistant spaces.  The alcoves are dedicated to the gods of the realm: "
"%^BOLD%^%^BLUE%^Callamir%^RESET%^, %^BOLD%^%^RED%^Jarmila%^RESET%^, %^CYAN%^Kismet%^RESET%^, "
"%^BOLD%^%^WHITE%^Kreysneothosies%^RESET%^, %^BOLD%^%^BLACK%^Lord Shadow%^RESET%^, "
"%^BOLD%^%^MAGENTA%^Lysara%^RESET%^, %^BOLD%^%^BLACK%^Nilith%^RESET%^, %^MAGENTA%^Nimnavanon%^RESET%^, "
"%^BOLD%^%^BLUE%^Ryorik%^RESET%^, and %^ORANGE%^The Faceless One%^RESET%^. You could %^YELLOW%^<look deityname> "
"%^RESET%^to consider the alcove of a particular deity, or %^YELLOW%^<read deityname> "
"%^RESET%^to learn a little more about them.",
    ({"callamir","Callamir","callamir alcove"}):({"This alcove is dedicated "
"to Callamir, the god of Luck and Trickery.  A cloth drape shows his symbol, a %^BOLD%^%^WHITE%^white "
"rabbit %^RESET%^running across an %^BOLD%^%^CYAN%^azure backdrop%^RESET%^.  Several bright coins, "
"gemstones, and other trinkets have been left here in offering, while a slender incense stick brightens "
"the surrounding air with a fresh and vibrant scent.  You could %^YELLOW%^<read callamir> %^RESET%^to "
"learn a bit more about him.","%^BOLD%^%^BLUE%^Callamir is the God of Luck and Adventure.  A self-"
"reliant trickster, he bids his followers to make their way by skill, cleverness and a little luck, and "
"to aid others in discovering new paths.%^RESET%^","wizish"}),
    ({"jarmila","Jarmila","jarmila alcove"}):({"This alcove is dedicated Jarmila, the goddess of Light "
"and Love.  A %^YELLOW%^golden shield %^RESET%^stands as her symbol, emblazoned with a %^RED%^crimson "
"rose%^RESET%^.  Offerings have been left in the form of brilliant rubies and sunstones, as well as "
"fresh roses and an assortment of other cheerful flowers.  You could %^YELLOW%^<read jarmila> "
"%^RESET%^to learn a bit more about her.","%^BOLD%^%^RED%^Jarmila is the Goddess of Light and Love.  Ever "
"optimistic, she bids her followers to spread her teachings of healing, renewal and rebirth, but also to be "
"absolutely unwavering against the forces of darkness.%^RESET%^","wizish"}),
    ({"kismet","Kismet","kismet alcove"}):({"This alcove is dedicated to Kismet, the goddess of Magic "
"and Knowledge.  Her symbol hangs in the air, a minor magical illusion of a %^ORANGE%^blank scroll %^RESET%^"
"crossed by a %^CYAN%^quill %^RESET%^and a %^RED%^smith's hammer%^RESET%^.  While the usual fare of shining "
"trinkets and gemstones have been offered here, unique to this particular alcove are also the scrolls and "
"parchments left in tribute.  You could %^YELLOW%^<read kismet> %^RESET%^to learn a bit more about her.",
"%^CYAN%^Kismet is the Goddess of Magic.  She controls the use of the weave by both arcane and psionic "
"spellcraft, and and delights in the discovery of new crafts.  She bids her followers to spread lore and "
"knowledge across the realm.%^RESET%^","wizish"}),
    ({"kreysneothosies","Kreysneothosies","kreysneothosies alcove"}):({"This alcove is dedicated "
"to Kreysneothosies, the god of Justice and the Home.  His symbol is displayed upon a drape of cloth, showing "
"a %^BOLD%^%^BLACK%^sword %^RESET%^crossing a %^ORANGE%^sheaf of wheat%^RESET%^.  As seems common to these "
"alcoves, offerings of coins and gems are present here, but there is also a basket holding gifts of fresh grain, "
"fruits and vegetables.  You could %^YELLOW%^<read kreysneothosies> %^RESET%^to learn a bit more about him.",
"%^BOLD%^%^WHITE%^Kreysneothosies is the God of Justice and the Home. A protector of civilisation, he bids his "
"followers to be even-handed in their dealings, and be respectful of laws that uphold order.%^RESET%^","wizish"}),
    ({"lord shadow","Lord Shadow","lord shadow alcove"}):({"This alcove is dedicated to Lord Shadow, "
"the god of Darkness and Tyranny.  The entire shrine has been painted %^BOLD%^%^BLACK%^jet-black%^RESET%^, with "
"a drape displaying the %^BOLD%^%^CYAN%^azure diamond %^RESET%^that serves as his symbol.  Coins and dark "
"gemstones gleam brightly, easier to spot against the shrine's dark backdropthan the scattering of black "
"violets also placed as an offering.  You could %^YELLOW%^<read lord shadow> %^RESET%^to learn a bit more "
"about him.","%^BOLD%^%^BLACK%^Lord Shadow is the God of Darkness. Calculating and ruthless, he aims to conquer "
"and rule over all who would oppose him. He bids his followers to spread fear and hopelessness across the realm, "
"so that all will come to know his ways.%^RESET%^","wizish"}),
    ({"lysara","Lysara","lysara alcove"}):({"This alcove is dedicated to Lysara, the goddess of Fate and "
"Death.  Against the plain back wall of the shrine hangs a three-ringed representation of her symbol, "
"one each cut from %^BOLD%^%^WHITE%^ivory%^RESET%^, %^BOLD%^%^BLACK%^ebony %^RESET%^and %^CYAN%^silver%^RESET%^.  "
"Moonstones and pieces of jade lie in offering here, along with fresh lillies that fill the air with a sweet scent"
".  You could %^YELLOW%^<read lysara> %^RESET%^to learn a bit more about her.","%^BOLD%^%^MAGENTA%^Lysara is the "
"Goddess of Fate and Death. Eternally patient, she watches over the souls of the deceased, and represents the ebb "
"and flow of time. She guides her followers to find peace through accepting the natural turnings of life, and "
"helping others to do the same.%^RESET%^","wizish"}),
    ({"nimnavanon","Nimnavanon","nim'navanon","Nim'navanon","nimnavanon alcove"}):({"This alcove is dedicated "
"to Nim'navanon, the god of Forests and Weather.  A cloth drape shows his symbol, of a %^BOLD%^%^BLACK%^wolf's paw "
"print %^RESET%^upon a circle of %^GREEN%^grass%^RESET%^.  Here, only a few coins have been offered, but where they "
"would normally be prolific in other shrines they have been replaced by an assortment of fresh leaves and flowers, "
"along with hunter's trophies of tooth and claw, and fragments of carved wood.  You could %^YELLOW%^<read nimnavanon> "
"%^RESET%^to learn a bit more about him.","%^MAGENTA%^Nim'navanon is the God of Nature. Watching over all of the "
"natural world, he bids his followers to preserve the balance of the wilds, and to oppose those who "
"threaten to tip its scales.%^RESET%^","wizish"}),
    ({"the faceless one","faceless one","The Faceless One","faceless one alcove","the faceless one alcove"}):
({"This alcove is dedicated to the Faceless One, the god of Lies and Murder.  No symbol marks the uniformly "
"%^BOLD%^%^BLACK%^gray alcove%^RESET%^, save for three %^RED%^blood-red teardrops %^RESET%^painted upon the back "
"wall.  Many coins of varying kinds have been left in offering here, along with bright trinkets and gems, and "
"even a finely crafted dagger.  You could %^YELLOW%^<read the faceless one> %^RESET%^to learn a bit more about "
"this god.","%^ORANGE%^The Faceless One is the deity of Lies and Murder. A secretive and chaotic god, the "
"faithful do not even agree on the race or gender of their deity, but certainly agree upon the use of murder, "
"mayhem and madness to spread chaos across the realm.%^RESET%^","wizish"}),
      ({"nilith","Nilith","nilith alcove","Nilith alcove"}):({"This alcove is dedicated "
"to Nilith, the goddess of Undeath and War.  A %^CYAN%^steel towershield %^RESET%^affixed to the wall "
"holds her symbol, a %^BOLD%^%^WHITE%^skeletal hand %^RESET%^holding a single wilted %^BOLD%^%^WHITE%^"
"ca%^RESET%^l%^BOLD%^l%^RESET%^a %^BOLD%^li%^RESET%^l%^BOLD%^y%^RESET%^. Uncut %^RED%^bl%^BOLD%^o"
"%^RESET%^%^RED%^od%^ORANGE%^s%^RED%^to%^BOLD%^n%^RESET%^%^RED%^e %^RESET%^and %^BOLD%^%^RED%^r"
"%^BLACK%^e%^RED%^d ag%^BLACK%^a%^RED%^te %^RESET%^have been left here in offering alongside "
"what look like mummified finger bones.  You could %^YELLOW%^<read nilith> %^RESET%^to "
"learn a bit more about her.","%^BOLD%^%^BLACK%^Nilith is the goddess of Undeath and War.  "
"A former tiefling general of Graez, she bids her followers to make war upon the living, ravage "
"the land, and take what they desire. Only the elite will be rewarded with immortal undeath.%^RESET%^","wizish"}),
      ({"ryorik","Ryorik","ryorik alcove","Ryorik alcove"}):({"This alcove is dedicated "
"to Ryorik, the god of Elements and Natural Disasters.  A %^BOLD%^%^BLACK%^dark gray %^RESET%^cloth drape, "
"tattered as though worn by the elements, shows his symbol: an elongated, curved %^BOLD%^silver scimitar "
"%^RESET%^against a %^BOLD%^%^BLACK%^sto%^RESET%^r%^BOLD%^%^BLACK%^m-cl%^RESET%^o%^BOLD%^%^BLACK%^ud "
"backdrop%^RESET%^.  Offerings of %^RESET%^%^RED%^g%^BOLD%^e%^RESET%^%^ORANGE%^m%^YELLOW%^s%^GREEN%^t"
"%^RESET%^%^GREEN%^o%^CYAN%^n%^BOLD%^e%^RESET%^%^MAGENTA%^s %^RESET%^in a riot of colors representing "
"the elements have been placed into the alcove.  You could %^YELLOW%^<read ryorik> %^RESET%^to "
"learn a bit more about him.","%^BOLD%^%^BLUE%^Ryorik is the God of Elements and Natural Disasters.  "
"Once a primordial force slumbering away the millenia, Ryorik was awakened with the help of some "
"denizens of the realms and has accepted the responsibility that comes with his divinity.  He "
"encourages his followers to revel in the elements rather than taming them and to teach others "
"to respect the destructive force they command.%^RESET%^","wizish"}),
  ]));
}

/*
Varda was removed, so I took her alcove out of Offestry ~Circe! 7/23/19
    ({"varda","Varda","varda alcove"}):({"This alcove is dedicated to Varda, goddess of War and Strength.  No "
"delicate cloth or detailed artwork shows her symbol, but instead her sigil of a %^RED%^bloodied %^BOLD%^%^BLACK%^iron "
"battle-axe %^RESET%^has been roughly painted upon the alcove's rear wall.  Plunder of all kinds has been left here in "
"offering, ranging through coins and gemstones to include several weapons also.  A scattering of blood-red poppies "
"lies across them all.  You could %^YELLOW%^<read varda> %^RESET%^to learn a bit more about her.","%^CYAN%^Varda is the "
"Goddess of War. She prizes strength and cunning, and bids her followers to do however they see fit, as long as they "
"have the power to enforce it.%^RESET%^","wizish"}),
*/
