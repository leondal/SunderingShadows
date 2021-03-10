#include <std.h>
#include <daemons.h>
#include "../undead.h"
inherit NPC;

int currentlist;

void create(){
   ::create();
   set_name("omthgar");
   set_id(({"omthgar","Omthgar","crafter","dwarvish crafter"}));
   set_short("Omthgar Stonehandle, dwarvish crafter");
   set_long("%^RESET%^%^CYAN%^Omthgar is a squat, stocky, muscular dwarf with a "
"thick beard of %^RED%^reddish brown %^CYAN%^hair and a %^RESET%^bald %^CYAN%^"
"head.  His skin is dark brown with a heavy track of %^BOLD%^%^BLACK%^blackish "
"scar tissue %^RESET%^%^CYAN%^running up and down his arms, shoulders and back."
"  Wearing little more then a thick %^BOLD%^%^BLACK%^dragonhide apron"
"%^RESET%^%^CYAN%^, a set of leather shorts and a pair of metal plated boots, "
"he storms around his warehouse with the presence of a demigod amongst his flock"
".  For here in his workshop he is lord, and the %^BOLD%^%^BLACK%^metal"
"%^RESET%^%^CYAN%^, %^ORANGE%^wood %^CYAN%^and %^BOLD%^%^RED%^g%^WHITE%^e"
"%^GREEN%^m%^BLUE%^s %^RESET%^%^CYAN%^all bend to his will as he reshapes and "
"reforms the bent and broken cast offs into new, serviceable works.  He "
"constantly has a %^YELLOW%^list%^RESET%^%^CYAN%^ in hand that you may want to "
"take notice of.%^RESET%^\n");
   set_gender("male");
   set_alignment(4);
   set_race("dwarf");
   set_body_type("human");
   set_class("fighter");
   set_hd(30,1);
   set_max_hp(300);
   set_hp(300);
   set("aggressive",0);
   currentlist = random(30)/10;
   command("speech grouche in a deep and vibrating tone");
   command("speak wizish");
}

void init() {
    ::init();
    add_action("my_listy","list");
    if(avatarp(TP) && TP->query_invis()) return 1;
    if(TP->query_invis()) return 1;
    if((int)TP->query_size() == 1 && TP->query_highest_level() > 20) {
      force_me("emote pulls a large chunk of metal from one of the many "
"piles.");
      force_me("say Start'd this place off doin' repairs on tha bits I found "
"in tha field, aye. Now lookit me, barely able ta keep up! Orders comin' in "
"left'n right.");
      force_me("emote pauses in his inspection of a scrap piece of armor and "
"looks over at you.");
      force_me("say Oi! Small'n. If'n ye see somethin' out in yer travels "
"that ye've not the need for, bring it round here. I might jes' trade ye for "
"it.");
      force_me("emote nods and goes back to looking at the piece of metal he "
"extracted.");
      force_me("say Gotta be human-size stuff though. Already gots me a good "
"supply o' small pieces I canna be rid of. Ain't many wee'ns doing much.");
      force_me("emote pitches the scrap back into the pile and stomps off "
"deeper into the warehouse in search of something else suitable.");
      force_me("say If'n ya wanna know what I'm after today, ye just check "
"out my %^YELLOW%^list%^RESET%^ here.");
      force_me("emote produces a crumpled piece of paper from his apron "
"pocket.");
    }
}

int my_listy(string str) {
    if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"Omthgar doesn't seem to notice you.");
      return 1;
    }
    if((int)TP->query_size() != 1 && !avatarp(TP)) {
      force_me("emoteat "+TP->query_name()+" looks $N over and shakes his "
"head.");
      force_me("say Afraid I ain't got anything spare fer folk your size.");
      force_me("emote returns to his work.");
      return 1;
    }
    if((int)TP->query_highest_level() < 21 && !avatarp(TP)) {
      force_me("emoteat "+TP->query_name()+" considers $N for a bit, but shakes "
"his head.");
      force_me("say I'm guessin' ye ain't up ta findin' what I'm after, kiddo.  "
"Dangerous stuff this.  Feel free ta come back if ya wanna help out when yer "
"upta the challenge, though.");
      force_me("emote gives a wink and puts the list back in his apron pocket.");
      return 1;
    }
    force_me("emoteat "+TP->query_name()+" looks up from his work and offers "
"the page for $N to look over.");
    tell_object(TP,"\n%^RESET%^%^ORANGE%^On the paper is a list scrawled in "
"messy handwriting:%^RESET%^");
    switch(currentlist) {
      case 0:
      tell_object(TP,"%^YELLOW%^Robe of the Dragon, four times enchanted.  "
"%^WHITE%^Rumored to be obtained from the island of Tonerra.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Boots of Speed, five times enchanted.  "
"%^WHITE%^Rumored to be kept within the Demongate Tower.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Leather headpieces of various kinds, four "
"times enchanted.  %^WHITE%^Said to be often used by the beings of Argentrock "
"island.%^RESET%^\n");
      break;
      case 1:
      tell_object(TP,"%^YELLOW%^Chainmail of the Azure Seas, five times "
"enchanted.  %^WHITE%^Said to be found somewhere upon the island of "
"Attaya.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Pants of the Dervish, five times enchanted.  "
"%^WHITE%^Rumored to be obtained within the Crystalline Tower upon "
"Attaya.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Crown of the Shadow Dancer, twice "
"enchanted.  %^WHITE%^Last known to have been interred in the burial tombs "
"beneath Lothwaite.%^RESET%^\n");
      break;
      case 2:
      tell_object(TP,"%^YELLOW%^Shimmering Cape, five times enchanted.  "
"%^WHITE%^Reported as able to be obtained from within the Crystalline Tower "
"upon Attaya.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Mithril Mesh Gauntlets, five times enchanted"
".  %^WHITE%^Also believed to be found upon Attaya island.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Robes of Sunlight or Moonlight, thrice "
"enchanted.  %^WHITE%^Rumored to have last been obtained upon the island "
"of Ovadexel.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Robes of Starlight or Nightmares, thrice "
"enchanted.  %^WHITE%^Also rumored to have last been obtained upon the island "
"of Ovadexel.%^RESET%^\n");
      break;
    }
    force_me("say If there's anything on there ya think ya kin get hold of fer me, jus' bring it back an' I'll make it worth yer while.");
    return 1;
}

void receive_given_item(object obj){
    string basename, *ids;
    if(!objectp(obj)) return;
    ids = obj->query_id();

    if((int)TP->query_size() != 1 && !avatarp(TP)) {
      force_me("emoteat "+TP->query_name()+" looks $N over and shakes his "
"head.");
      force_me("say Sorry, I ain't got anythin' ta reward ya with fer such "
"things.  Ain't proper ta take it.");
      force_me("emote puts the item back down on the table.");
      force_me("drop "+ids[0]);
      return 1;
    }
    if((int)TP->query_highest_level() < 21 && !avatarp(TP)) {
      force_me("emoteat "+TP->query_name()+" considers $N for a bit, but shakes "
"his head.");
      force_me("say Ain't a way ya got that by yerself, kiddo.  And nothin' I "
"have ta give ya for it, would be of any use to ya.  Ya come back later when "
"yer stronger.");
      force_me("emote puts the item back down on the table.");
      force_me("drop "+ids[0]);
      return 1;
    }
    basename = base_name(obj);
    force_me("emote inspects the garment with a crystal lense.");
    switch(currentlist) {
      case 0:
        if(basename == "/d/islands/tonerra/obj/mrobe") {
          if((int)obj->query_property("enchantment") != 4) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJS"smallshirt")->move(TO);
          force_me("drop shirt");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        if(basename == "/d/dagger/marsh/tower/obj/speedboots") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJS"smallboots")->move(TO);
          force_me("drop boots");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        if(basename == "/d/common/obj/rand/rand_leath_head") {
          if((int)obj->query_property("enchantment") != 4) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJS"smallhat")->move(TO);
          force_me("drop fedora");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        force_me("say Don' need anythin' like this today.  Ya kin check out my "
"%^YELLOW%^list%^RESET%^ iff'n ya wanna know what I'm after.");
        force_me("emote puts it back down on the table.");
        force_me("drop "+ids[0]);
        return 1;
      break;

      case 1:
        if(basename == "/d/attaya/obj/azure") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJS"smallchain")->move(TO);
          force_me("drop chain");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        if(basename == "/d/attaya/obj/shorts") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJS"smallpants")->move(TO);
          force_me("drop pants");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        if(basename == "/d/barriermnts/lothwaite/obj/shadow_circlet") {
          if((int)obj->query_property("enchantment") != 2) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJS"smallberet")->move(TO);
          force_me("drop beret");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        force_me("say Don' need anythin' like this today.  Ya kin check out my "
"%^YELLOW%^list%^RESET%^ iff'n ya wanna know what I'm after.");
        force_me("emote puts it back down on the table.");
        force_me("drop "+ids[0]);
        return 1;
      break;

      case 2:
        if(basename == "/d/attaya/obj/shimmeringcape") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJS"smallcloak")->move(TO);
          force_me("drop pendant");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        if(basename == "/d/attaya/obj/bish_gauntlets") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJS"smallgauntlets")->move(TO);
          force_me("drop gauntlets");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        if(basename == "/d/islands/dreams/obj/moonlight_robe" || basename == "/d/islands/dreams/obj/sunlight_robe") {
          if((int)obj->query_property("enchantment") != 3) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          new(OBJS"smallmrobe")->move(TO);
          force_me("drop robe");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        if(basename == "/d/islands/dreams/obj/starrobe" || basename == "/d/islands/dreams/obj/nightmare_robe") {
          if((int)obj->query_property("enchantment") != 3) {
            force_me("say Afraid this ain't appropriately enchanted.  No good "
"ta me, this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Aye, this is the one!  Lemme get ye somethin' nice fer "
"yer troubles.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          new(OBJS"smallmrobe2")->move(TO);
          force_me("drop robe");
          force_me("say Thanks fer yer help!");
          return 1;
        }
        force_me("say Don' need anythin' like this today.  Ya kin check out my "
"%^YELLOW%^list%^RESET%^ iff'n ya wanna know what I'm after.");
        force_me("emote puts it back down on the table.");
        force_me("drop "+ids[0]);
        return 1;
      break;
    }
    force_me("say Don' need anythin' like this today.  Ya kin check out my "
"%^YELLOW%^list%^RESET%^ iff'n ya wanna know what I'm after.");
    force_me("emote puts it back down on the table.");
    force_me("drop "+ids[0]);
    return 1;
}
