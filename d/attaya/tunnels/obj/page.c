#include <std.h>
inherit OBJECT;

#define LANGUAGES ({"common",\
"drow",\
"elven",\
"giant",\
"undercommon",\
"kobold",\
"common",\
"common",\
"common",\
"elven",\
"elven",\
"common",\
"drow"})



void set_text();



void create(){
      set_name("paper");
      set_id(({"paper", "page", "ripped page"}));
   	set_text();

      set_short("torn piece of paper");
      set_long("a ripped piece of paper, torn from a book of some sort."
              +" It has some writing on it."); 
 
   	set_lore("This page seems to have come from some kind of arcane"
              +" work. It is the sort of thing that mages and sorcerers"
              +" would probably be interested in. You have heard rumours"
              +" that the Archmage Stefano Esposair was very interested"
              +" in these sorts of subjects at one time\n");
   	set_property("lore difficulty",31);
   	set_weight(2);
   	set_value(200);
}

void set_text()
{
  int i,y;
  string text, language;
      y = random(sizeof(LANGUAGES));
      language = LANGUAGES[y];
      i = random(12);
  switch(i)
  {
  case 0:
    text = "On the third day of the second moon of Winterstime the"
          +" Great Lord Ahmul Raj sent forth the hordes of Baatuz to"
          +" do battle on the inhabitants of the realm of Plezar."
          +" With the opening of the fire portal, the devil armies"
          +" were able to spill through onto the planes of  Akanth in"
          +" force and their numbers were like unto the sands of the"
          +" beach and their dark flapping wings blackened the skies"
          +" like locusts.\n\n"

          +"Gsh vashud grepaz skar flsh vashud zagaz slunm flsh"
          +" grnlackzturr, vashud Brrz Shllorg Ulshkep Ramen kurrzn"
          +" bleth vashud murzzd flsh Baatuhz glun versh ahgzun"
          +" vashud vshlagolmzd flsh vashud hxagrin flsh Pelshr."
          +" Omzet vashud hashzlg flsh vashud quaaltah razhgeb,"
          +" vashud baat fargezzd tozn laghuz glun zurk dazzhor"
          +" vashud kormtuzd flsh Akanth golm bleth ngzd vahoren"
          +" orgtazd tozn blsh zshdun vashud mrrshzd flsh vashud"
          +" veshod ngzd vahoren rejh vrishnepp plethzd fahrlgend"
          +" vashud florrshzd gruk cremglozzd.";
    break;
  case 1:
    text = "The summoning of devils is a practice most full of perils. If"
          +" you are to embark upon it, have a care. Let caution and"
          +" precision be your watchwords. Follow the instructions in the"
          +" texts most closely in every detail, for the slightest"
          +" deviation can spell disaster.\n"
          +"However, with those cautions made plain, know also that for"
          +" those able to gain the service of the inhabitants of the"
          +" lower planes, great power can be taken.\n\n"

          +"Vaarghutchn Baatzd ng zek sverrakh wrch urkhj flsh zalslazd."
          +" Znch bhag ngzd glun zarkn hagsh glt, praxag zek shnerrg."
          +" Forgag zerrkaz unz vaqrrtn kurgh bhaarg fivarrhazzkhzd."
          +" Grnhazrh vashud laghzazd golm vashud kahrazd wrch jaalrex"
          +" golm zimchaz gragzeh, xplar vashud vraxhelzaz baht karagh"
          +" grromhaz.\n"
          +"Unctulazn, omzet vahzhn zerrkazd glaxxn urrwsh, venhagh"
          +" undzag vahkarr xplar vahzhn laghuz glun maargh vashud"
          +" xenshaz flsh vashud vshlagolmzd flsh vashud gruntahrx"
          +" kormtuzd, brzz zimshaz baht kurgh maaragzh.";
    break;
  case 2:
    text = "In a time of much sacrifice, the great Lord Ahmul Raj grew"
          +" stronger still and conquered many of the realms surrounding"
          +" his own. Tall he stood and proud and all around feared him."
          +" \n\n"

          +"Golm zek turr flsh wrchug krsplshacz, vashud brzz Shllorg"
          +" Ulshkep Ramen slrrpn zimmarkhn ingzen unz inngzazn wrgled"
          +" flsh vashud hxagrinzd enslazkapchn gahoren nrrch. Ga dakuzn"
          +" takshrrn unz gnushorn unz lagak znnuslazn gahan.";
    break;
  case 3:
    text = "The realm of the seventh hell was invaded by a wretched bunch"
          +" of upstart adventurers, followers of the miserable Gods of"
          +" light, one and all. By luck and treachery they stole the key"
          +" to a portal from their world to his and with the help of"
          +" their conniving Gods they found their way to the very home"
          +" of the great Lord and launched their foul magicks upon him"
          +" as he slept. Much was their delight when he fell and their"
          +" vicory seemed upon them. So little did they know that they"
          +" did not realise that even if he did not return, a successor"
          +" would arise and bring a peril just as deadly as his own.\n\n"

          +"Vashud hxagrin flsh vashud urrgaz baatu ngzn traalhaxzn ege"
          +"vashud umslazgn trath flsh nishov stneerezd, grnhazrhugzn"
          +" flsh vashud glunkgn murgzazd flsh blershz, ashk unz lagak."
          +" Ege dmerz unz finblazhargzurz vahor tarkazn vashud intakz"
          +" dun zek razhgeb plenshug vahoren xavakh dun gahoren unz"
          +" omzet vashud nrrsh flsh vahoren imshalakzechn murgzazd vahor"
          +" rnkazn vahoren nmptaz dun vashud gelug aghluh flsh vashud"
          +" brzz Shllorg unz frrdakzn vahoren grugug nimplazd hagsh"
          +" gahan ven ga dimshazn. Wrchug ngzn vahoren umprlazz zut ga"
          +" stozn unz vahoren kraaklahd minshuzn hagsh vahux. Rrnch"
          +" denwrchug vershzn vahor venhagh vahkarr vahor den vershzn"
          +" grunsh vahkarr norhaz znch den vershzn misplaz, zek"
          +" vinalshurraz nglem flezun unz varrang zek zalslaz znikk kurz"
          +" dshnakring kurz gahoren nrrch.";
    break;
  case 4:
    text = "If you wish to summon us, you had best be prepared with a"
          +" bargain to offer when we arrive. We know you like to keep"
          +" your protective magic circles in place but, well, there are"
          +" ways around those and in the end it is your death if you"
          +" annoy us too much.\n\n"

          +"znch bhag glek glun vaarghutz glar, bhag praxzn lugch kurgh"
          +" vasazn omzet zek nullutz glun zsartz zut glarz unneah. Glarz"
          +" venhagh bhag gruk glun niptraz bhaarg shalzrem nimplaz"
          +" pleztarzd golm szzat, unct, flur, deneah ngzd nmptazd furbeh"
          +" vahzhn unz golm vashud nek glt ng bhaarg wart znch bhag"
          +" heglax glar bhug wrchug.";
    break;
  case 5:
    text = "Even a little knowledge of the devourer is a dangerous thing."
          +" He has ways to get into your brain from the simplest thought"
          +" and infect you from within like a canker.\n\n"

          +"norhaz zek denwrchug venhagraxn flsh vashud shlumshlakan ng"
          +" zek dshnakl gretz. Ga praxz nmptazd vun jck golmdun bhaarg"
          +" xax plenshug vashud aglkch vlesz unz glanz bhag plenshug"
          +" golmzet gruk zek urrshd.";
    break;
  case 6:
    text = "Anyone preparing to summon a devil should know that they"
          +" always follow up on anything they think they are owed from a"
          +" bargain. If they cannot get what they think is owing, they"
          +" may try to reclaim the price from the summoner's soul and"
          +" flesh.\n\n"

          +"Naaraknashk vasazchn glun vaarghutz zek baat englem venhagh"
          +" vahkarr vahor sta grnhazrh hg gsh naarakngretz vahor yleb"
          +" vahor ngzd nrrzn plenshug zek nullutz. Znch vahor denbaht"
          +" jck ut vahor yleb vahor ngzd nrrzn, vahor unk ot ukplaz"
          +" vashud dex plenshug vashud vaarghutzugze grelmz unz mung.";
    break;
  case 7:
    text = "Hearts of unicorns can be used to strengthen the spell by"
          +" burning them on the brazier during the incantation. This is"
          +" most effective when you plunder the organs shortly before"
          +" the casting, and especially if it is still bleeding.\n\n"

          +"Gushazd flsh klaklatzd baht kurgh lektzn glun zimmzakzl"
          +" vashud karagh ege praalnchn vahux gsh vashud nishab klen"
          +" vashud plek. Vahz ng wrch klagratznl zut bhag naklz vashud"
          +" lokzd ungling dur vashud lamparz, unz fokat znch glt ng"
          +" ingzen drrpgunchn.";
    break;
  case 8:
    text = "The great Lord called upon all to hail him and spread word of"
          +" his victory. And there was much howling and gnashing of"
          +"teeth within the ranks of the devils, most of whom could"
          +" still taste blood on their lips.\n\n"

          +"Vashud brzz Shllorg snugzn hagsh lagak glun kuz gahan unz"
          +" pleshz azzkh flsh gahoren kraaklahd. Unz deneah ngzn wrchug"
          +" rahrchn unz snatzchn flsh vetzd golmzet vashud corlazd flsh"
          +" vashud baatzd, wrch flsh teg aglem slev drrp gsh vahoren"
          +" splizd.";
    break;
  case 9:
    text = "%^RED%^Asfero Loesris\n"
           +"%^BLUE%^'%^GREEN%^Essays on Items of Magical Worth%^BLUE%^'"

           +"\n\n%^YELLOW%^Sulphur %^RESET%^%^GREEN%^- Forms orthohombic"
           +" bright yellow crystals.  Found commonly as encrusting"
           +" masses around volcanic vents and fumaroles.  It has been"
           +" speculated that it is the association with volcanic areas"
           +" that makes sulphur suitable for spells which require or"
           +" create some form of combustion.  %^MAGENTA%^See also"
           +" entries for Bat Guano and Phosphorus.\n\n"

           +"%^YELLOW%^Snow Crystals %^RESET%^%^GREEN%^- Precipitation"
           +" taking the form of minute ice crystals formed from an"
           +" aqueous vapour in the air.  Early expirments in the use of"
           +" snow crystals as the key component for the conjuration of"
           +" ice elementals looked promising, however were proven"
           +" unsucessful.  The theory of the incantation and the"
           +" components seemed plausible, in practice though it was"
           +" impossible to maintain the snow crystals during the"
           +" casting.  It seems likely that the energy created by the"
           +" manipulation of the weave is sufficient to melt the"
           +" crystals before the critical moment.  %^MAGENTA%^See also"
           +" entries for Water.\n\n"

           +"%^YELLOW%^Clay %^RESET%^%^GREEN%^- A hydrous aluminum"
           +" silicate.  Earth of various colours with a fine texture."
           +" It is compact and brittle when dry but malleable and"
           +" tenacious when wet.  Baked clay I have as yet to find a use"
           +" for as major or minor component, whilst it holds its shape"
           +" perfectly is seemingly unable to convey this ability to a"
           +" target without also making it brittle.  The use of clay in"
           +" the conjuration of earth elementals is vital, though the"
           +" clay in use must be kept moist so that it remains soft."
           +"  Far superior results for this casting than ooze."
           +"  %^MAGENTA%^See also entries for Ooze.\n\n"

           +"%^YELLOW%^Incense %^RESET%^%^GREEN%^- An aromatic substance"
           +" that exhales perfume during combustion.  I have found that"
           +" the type of incense used has little impact on the success"
           +" of the conjuration of an air elemental, though I have noted"
           +" that incense derived from some spices can have a benefical"
           +" impact upon the temperament of the elemental."
           +"  %^MAGENTA%^See also entries for Ginger, Saffron and"
           +" Perfume.\n\n"

           +"%^YELLOW%^Water %^RESET%^%^GREEN%^- Colourless liquid"
           +" compound.  A useful component in a variety of castings"
           +" predominantly as a carrier liquid for other potent"
           +" components.  In its own right it has been proven to"
           +" facilitate the conjuration of water elementals."
           +"  %^MAGENTA%^See also entries for Sand.\n\n"

           +"%^YELLOW%^Sand %^RESET%^%^GREEN%^- Hard, granular comminuted"
           +" rock material.  In combination with pure water can be used"
           +" in the conjuration of a water elemental.  Dyed in a variety"
           +" of different shades it can also be used as a carrier for"
           +" vibrant, blindingly bright colors.  %^MAGENTA%^See also"
           +" entries for Water and Colored Sand.\n\n"

           +"%^YELLOW%^Ooze %^RESET%^%^GREEN%^- Slimy mud or moist,"
           +" spongey soil that exudes moisture.  In early attempts to"
           +" conjure earth elementals I have used ooze with some"
           +" success.  The results are far harder to predict, however,"
           +" than with moist soft clay and the creatures summoned have"
           +" little cognitive ability.  %^MAGENTA%^See also entries for"
           +" Soft Clay.";
    break;
  case 10:
    text = "%^RED%^It is often misunderstood by those new to the study of"
          +" summoning and conjuration that the two are not necessarily"
          +" synonomous terms.  To summon and to conjure a creature are"
          +" not always the same arcane processes.  Conjuration can be"
          +" said to be a form of, or one method for the summoning"
          +" creatures from other planes of existance.  There are however"
          +" a number of alternative methods available to those skilled"
          +" and learned in arcane lore.\n\n"

          +"%^RED%^In short, conjuration is the summoning of creatures"
          +" from otherworldly planes for a finite period of time.  This"
          +" can also in some circumstances allow the caster to command"
          +" the creature directly to carry out actions that may be"
          +" contrary to its will.\n\n"

          +"%^RED%^Summoning as a broad field of study incorporates"
          +" conjuration but can also include the study of lesser and"
          +" greater summoning.  Whilst conjuration is only ever a time"
          +" limited summoning of a creature both lesser and greater"
          +" summoning have the power to summon creatures to this realm"
          +" for an unlimited period of time.  The distinction between"
          +" the two forms of summoning relate primarily to the creatures"
          +" that are being called.  Lesser summoning can be used to"
          +" bring forth imps and comparable creatures, whilst demons,"
          +" devils and any creatures of a similar nature require the"
          +" arts of greater summoning.  Lesser creatures that are"
          +" summoned can to some extent be compelled to action, though"
          +" this is highly unpredictable.  Greater creatures may be"
          +" persuaded to enter into pacts, agreements of bargains with"
          +" their summoner but all recorded attempts to compel action"
          +" have thus far failed brutally.  The hazards involved in"
          +" summoning any creature cannot be overstated.\n\n"

          +"%^RED%^Even the most simple of lesser summonings requires"
          +" many years of dedicated study of associated crafts, one that"
          +" is most commonly recognized outside of the particular school"
          +" of magic is the use of circles.  This is again a term that"
          +" encompasses a broad field of study that incorporates circles"
          +" of protection, circles of summoning and circles of power.";
    break;
  case 11:
    text = "%^BOLD%^%^RED%^This iappears to be a copy of a letter from"
          +" Lithgi Ralloton to the Lochir Magical Institute concerning"
          +" Demonology%^RESET%^\n\n"

          +"%^BOLD%^%^CYAN%^...These creatures, in a state of separate"
          +" existence in their own planes once admitted to ours are not"
          +" indifferent to the affairs of mortality, indeed they are far"
          +" from incapable of influencing it.  The results of several"
          +" documented experiments have witnessed the casters being"
          +" driven insane by the battle to control the weave around them"
          +" to maintain wards and the summoning and to control the will"
          +" of the creature they have brough into these realms.  This"
          +" effort it would seem preoccupies them to such an extent that"
          +" they are then unable to retain control of their own minds. "
          +" This frightful disorder in not a general afflicition of"
          +" insanity, although it appears closely related to that most"
          +" horrid of maladies and has been know to precipitate its"
          +" onset in those of a particular disposition.\n\n"

          +"%^BOLD%^%^CYAN%^The distinction can be made however, in that"
          +" in true cases of insanity their senses offer in vain"
          +" testimony against the fantasy of the deranged imagination. "
          +" Whereas the afflicition brought about by those caught"
          +" between this realm and the powers of another seem no longer"
          +" able to distinguish between either.  Conjecture may offer"
          +" that the hallucinations they suffer are in actuality the"
          +" very real visions of demonic creatures in a parallel plane. "
          +" More than one learned physician has given their attestation"
          +" to the existence of this most distressing complaint and have"
          +" agreed upon its cause.\n\n"

          +"%^BOLD%^%^CYAN%^What little information can be gained from"
          +" those so afflicted seems to be minimal, other than as an"
          +" unspoken warning of the dangers of such manipulations of the"
          +" weave.  Whilst I continue my explorations for an archmage"
          +" willing and able to speak coherently on the subject it seems"
          +" my efforts must contiue to take me to distant reaches of the"
          +" realms.\n\n"

          +"%^BOLD%^%^CYAN%^Whilst I have been able to locate the"
          +" residences of several illustrious practitioners of magic who"
          +" have been associated with areas of research aligned to my"
          +" own, I am as yet unable to report a successful scholarly"
          +" exchange.  Those with the mental prowess to withstand the"
          +" risk of lunacy seem to have an unnerving propensity for"
          +" discovering a less cerebral, yet no less injurious fate at"
          +" the hands, teeth and claws of those creatures they have"
          +" summoned...";
    break;
  }
  set("language", language);
  set("read",text);
}
