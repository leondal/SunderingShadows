// Nienne's faction system. To make the cities work! August 2015... wait, Nov 2016 and into 2017!

// This system includes a dual list of factions, and is intended to bring cities to life.
// Longterm, it's intended to allow for players to influence their own standing (quests, attacks,
// etc) or potentially gain official ranks within the town.

// For now, it's tied in to the ambience.c object in each city, which manipulates messages and
// reactions in that city area (phase 1). Only Tharis is installed so far, for testing purposes,
// but more will be rolled out once this is working well.

// To install a new faction, please set up factionname.o in /std/factions, with a function for
// initialise_status(object theplayer). This will give a default standing for the player the
// first time they encounter that faction. Eg/ humans will likely be neutral or friendly with
// most groups, whereas a thieves guild may default to friendly ranking only for thieves and
// bards on a first encounter. Also please add the faction to the relevant array.

// Arrays: OK_FACTIONS stores all standard and publically-known cities, which players may expect
// to gain status with in standard interactions. HIDDEN_FACTIONS is just that, ones that are
// not readily apparent, and may be guilds, player groups, or other secret gatherings. The player
// UI will not reveal this list by default unless a player has already gained standing with them.

// Rankings: on a sliding scale, hostile -> unfriendly -> indifferent -> friendly -> respected.
// These will change the way city echoes & NPCs react to the player (phase 2). Also two special
// flags to override other ranks, hunted & appointed - which can only be manually set (phase 3).
// These should be given by immortals based on interactions. Hunted are those beyond just
// banned from the city/area, who later can have actual bounties, pursuit, and rewards for capture.
// Appointed are city officials, which should be limited to HMs & should allow commands later to
// direct city guards, etc.
// Scale is appointed/respected/friendly/indifferent/unfriendly/hostile/hunted. Matching number
// values: 6000/4000 to 5999/2000 to 3999/-1999 to 1999/-3999 to -2000/-5999 to -4000/-6000.

// Initial rankings: all characters start somewhere between hostile and friendly. A files for each
// faction in /std/factions specify the clauses (race, class, etc) to give default standings for
// new characters. These then get adjusted by player actions in-game (phase 3) by quests, attacks,
// etc. Also they can be manually overridden/adjusted by immortals.

#include <security.h>
#include <dirs.h>

mapping factions;
nosave string current;

int valid_access(string who);
int account_exists(string who);
int is_ok_faction(string thisfaction);
void initialize_faction(string who,string thisfaction);
int has_faction(string who,string thisprofile,string thisfaction);
int reset_faction(string who,string thisprofile,string thisfaction);
void pk_reset_hostile(string who);
int query_faction(string who,string thisprofile,string thisfaction);
int adjust_faction(string who,string thisprofile,string thisfaction,int amount);
int set_faction(string who,string thisprofile,string thisfaction,int amount);
mapping query_active_factions(string who);
void display_factions(object ob,string who);

//#define OK_FACTIONS ({ "tharis","tonovi","shadow","tsarven","antioch","torm","juran" }) // eventually! Not all in yet.
#define OK_FACTIONS ({ "tharis","shadow","torm","tsarven","antioch","tonovi","juran","synoria" })
#define HIDDEN_FACTIONS ({ "enclave of shadows","independent thieves guilds","rilynath","circle of light","silver thread" })

void create() {
    seteuid(getuid());
    current = 0;
    factions = ([]);
}

int valid_access(string who) {
    if(!who) return 0;
    if(geteuid(previous_object()) == UID_ROOT) return 1;
    if(archp(this_player())) return 1;
    if(!this_player()) return 0;
    if((string)this_player()->query_name() != who) return 0;
    return 1;
}

int account_exists(string who) {
    if(file_size(DIR_FACTIONS+"/"+who+".o") > -1) return 1;
    return 0;
}

int is_ok_faction(string thisfaction) {
    if((member_array(thisfaction,OK_FACTIONS) == -1) && (member_array(thisfaction,HIDDEN_FACTIONS) == -1)) return 0;
    return 1;
}

// for the player's first encounter with the faction under the active profile. Sets their expected first impression.
// note: this & has_faction require the active player object. all other functions only require name/profile/faction.
void initialize_faction(string who,string thisfaction) {
    object theplayer;
    int startval;
    string myprofile, MyFile, *myfactions;

    if(!who || !thisfaction) return;
    theplayer = find_player(who);
    if(!objectp(theplayer)) return;
    myprofile = (string)theplayer->query("relationship_profile");
    if(!myprofile) return;
    if(!is_ok_faction(thisfaction)) return;
    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);
    if(!factions[myprofile]) factions[myprofile] = ([]);
    myfactions = keys(factions[myprofile]);
    if(sizeof(myfactions)) {
      if(member_array(thisfaction,myfactions) != -1) return;
    }

    MyFile = "/std/factions/"+thisfaction+"_data.c";
    if(!file_exists(MyFile)) return;

    startval = (int)MyFile->query_start_attitude(theplayer);
    if(!intp(startval)) return;

    factions[myprofile][thisfaction] = startval;
    tell_object(find_player("nienne"),"Initialized faction "+thisfaction+" under profile "+myprofile+" to "+startval+".");
    save_object(DIR_FACTIONS+"/"+current);
}

// to query if they have the faction already active on this profile! Used IC to trigger initialize if needed.
// note: this & initialize_faction require the active player object. all other functions only require name/profile/faction.
int has_faction(string who,string thisprofile,string thisfaction) {
    object theplayer;
    string *myfactions;

    if(!who || !thisprofile || !thisfaction) return 0;
    if(!is_ok_faction(thisfaction)) return 0;
    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);
    if(!factions[thisprofile]) return 0;
    myfactions = keys(factions[thisprofile]);
    if(sizeof(myfactions)) {
      if(member_array(thisfaction,myfactions) != -1) return 1;
    }
    return 0;
}

// wipes the existing rep on the specified profile & faction. Use with care! Will auto-initialise on next encounter.
void reset_faction(string who,string thisprofile,string thisfaction) {
    string *myfactions;
    if(!who || !thisprofile || !thisfaction) return 0;
    if(!is_ok_faction(thisfaction)) return 0;
    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);
    if(!factions[thisprofile]) return;
    myfactions = keys(factions[thisprofile]);
    if(!sizeof(myfactions)) return;
    if(member_array(thisfaction,myfactions) == -1) return;
    map_delete(factions[thisprofile],thisfaction);
    save_object(DIR_FACTIONS+"/"+current);
}

// to wipe all hostile- or hunted-rank faction standings. This should trigger on a PK to clean any history there.
// if certain factions are naturally hostile to a character type, they will simply reconfigure on the next encounter.
// this does not automatically wipe appointed rank, I would prefer this done manually by imms if the PK merits
// such a situation, rather than it being automatic.
void pk_reset_hostile(string who) {
    string *myprofiles, *myfactions;
    int i, j;
    mapping currentfaction;
    if(!who) return 0;
    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);
    myprofiles = keys(factions);
    if(!sizeof(myprofiles)) return;

    for(i=0;i<sizeof(myprofiles);i++) {
      myfactions = keys(factions[myprofiles[i]]);
      if(!sizeof(myfactions)) continue;
      currentfaction = ([]);
      for(j=0;j<sizeof(myfactions);j++) {
        if(factions[myprofiles[i]][myfactions[j]] > -4000)
          currentfaction[myfactions[j]] = factions[myprofiles[i]][myfactions[j]];
      }
      factions[myprofiles[i]] = currentfaction;
    }
    save_object(DIR_FACTIONS+"/"+current);
}

// query where their rank is currently set. will initialize to default if it doesn't exist, so the world can react accordingly.
int query_faction(string who,string thisprofile,string thisfaction) {
    if(!who || !thisprofile || !thisfaction) return 0;
    if(!is_ok_faction(thisfaction)) return 0;
    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);
    if(!factions[thisprofile]) { initialize_faction(who,thisfaction); }
    if(!factions[thisprofile]) return 0; // faction does not exist!!
    if(!factions[thisprofile][thisfaction]) { initialize_faction(who,thisfaction); }
    if(!factions[thisprofile][thisfaction]) return 0; // must be at zero rating already!
    return factions[thisprofile][thisfaction];
}

// additive adjustment to the faction value. Good for doing quests/etc to bump reputation up/down.
int adjust_faction(string who,string thisprofile,string thisfaction,int amount) {
    if(!who || !thisprofile || !thisfaction || !amount) return 0;
    if(!is_ok_faction(thisfaction)) return 0;
    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);
    if(!factions[thisprofile]) { initialize_faction(who,thisfaction); }
    if(!factions[thisprofile][thisfaction]) { initialize_faction(who,thisfaction); }
    if(!factions[thisprofile][thisfaction]) factions[thisprofile][thisfaction] = amount;
    else factions[thisprofile][thisfaction] += amount;
    save_object(DIR_FACTIONS+"/"+current);
    return 1;
}

// sets the faction to a specified value, use carefully - overrides all previous progress.
int set_faction(string who,string thisprofile,string thisfaction,int amount) {
    if(!who || !thisprofile || !thisfaction || !amount) return 0;
    if(!is_ok_faction(thisfaction)) return 0;
    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);
    if(!factions[thisprofile]) { initialize_faction(who,thisfaction); }
    if(!factions[thisprofile][thisfaction]) { initialize_faction(who,thisfaction); }
    factions[thisprofile][thisfaction] = amount;
    save_object(DIR_FACTIONS+"/"+current);
    return 1;
}

// use this to generate a list for player UI. All visible factions, plus any hidden they have accessed as well.
mapping query_active_factions(string who) {
    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);
    return factions;
}

void display_factions(object ob,string who) {
    string *myprofiles, *myfactions, currentprofile, currentvalue;
    int defaultok = 0, i, j;

    if(current != who) {
	current = who;
	if(account_exists(current)) restore_object(DIR_FACTIONS+"/"+current);
      else factions = ([]);
    }
    if(!factions) factions = ([]);

    if((string)ob->query_name() != who) tell_object(ob,"\n%^BOLD%^%^YELLOW%^Displaying factions for "+capitalize(who)+":");
    tell_object(ob,"\n%^RESET%^%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^> %^BOLD%^%^GREEN%^Factions %^RESET%^<%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");

    if(!account_exists(current)) {
      if(avatarp(ob)) {
        tell_object(ob,"\n%^YELLOW%^Nil data. Please check the name you have entered, as the character may not exist. "
          "Otherwise, they may simply not have encountered any in-game factions yet!");
        tell_object(ob,"\n%^RESET%^%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        return;
      }
      tell_object(ob,"\n%^YELLOW%^You haven't encountered any in-game factions yet!");
      tell_object(ob,"\n%^RESET%^%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
      return;
    }

    // run default first, just for clarity's sake!
    myprofiles = keys(factions);
    if(member_array("default",myprofiles) != -1) {
      defaultok = 1;
      myprofiles -= ({ "default" });
    }
    if(avatarp(ob)) tell_object(ob,"\n   %^YELLOW%^Profile ID: default%^RESET%^");
    else tell_object(ob,"\n   %^YELLOW%^Character default:%^RESET%^");
    if(!defaultok) tell_object(ob,"     %^RESET%^%^GREEN%^Nil.");

    else {
      myfactions = keys(factions["default"]);
      for(j=0;j<sizeof(myfactions);j++) {
        switch(factions["default"][myfactions[j]]) {
          case 6000: currentvalue = "%^MAGENTA%^appointed"; break;
          case 4000..5999: currentvalue = "%^BLUE%^respected"; break;
          case 2000..3999: currentvalue = "%^GREEN%^friendly"; break;
          case -1999..1999: currentvalue = "%^CYAN%^indifferent"; break;
          case -3999..-2000: currentvalue = "%^ORANGE%^unfriendly"; break;
          case -5999..-4000: currentvalue = "%^RED%^hostile"; break;
          case -6000: currentvalue = "%^BOLD%^%^RED%^hunted"; break;
          default: currentvalue = "%^BOLD%^%^RED%^error, please contact a wiz%^RESET%^"; break;
        }
        if(avatarp(ob)) tell_object(ob,"     %^BOLD%^%^WHITE%^%^"+capitalize(myfactions[j])+": %^RESET%^"+currentvalue+" ("+factions["default"][myfactions[j]]+")%^RESET%^");
        else tell_object(ob,"     %^BOLD%^%^WHITE%^%^"+capitalize(myfactions[j])+": %^RESET%^"+currentvalue+"%^RESET%^");
      }
    }

    if(!sizeof(myprofiles)) { // no others to print!!
      tell_object(ob,"\n%^RESET%^%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
      return;
    }

    for(i=0;i<sizeof(myprofiles);i++) {
      myfactions = keys(factions[myprofiles[i]]);
      if(sizeof(myfactions)) {
        if(avatarp(ob)) tell_object(ob,"\n   %^YELLOW%^Profile ID: "+myprofiles[i]+"%^RESET%^");
        else {
          currentprofile = capitalize(myprofiles[i]);
          currentprofile = replace_string(currentprofile,"_999","");
          currentprofile = replace_string(currentprofile,"_"," ");
          tell_object(ob,"\n   %^YELLOW%^"+currentprofile+":%^RESET%^");
        }
        for(j=0;j<sizeof(myfactions);j++) {
          switch(factions[myprofiles[i]][myfactions[j]]) {
            case 6000: currentvalue = "%^MAGENTA%^appointed"; break;
            case 4000..5999: currentvalue = "%^BLUE%^respected"; break;
            case 2000..3999: currentvalue = "%^GREEN%^friendly"; break;
            case -1999..1999: currentvalue = "%^CYAN%^indifferent"; break;
            case -3999..-2000: currentvalue = "%^ORANGE%^unfriendly"; break;
            case -5999..-4000: currentvalue = "%^RED%^hostile"; break;
            case -6000: currentvalue = "%^BOLD%^%^RED%^hunted"; break;
            default: currentvalue = "%^BOLD%^%^RED%^error, please contact a wiz%^RESET%^"; break;
          }
          if(avatarp(ob)) tell_object(ob,"     %^BOLD%^%^WHITE%^%^"+capitalize(myfactions[j])+": %^RESET%^"+currentvalue+" ("+factions[myprofiles[i]][myfactions[j]]+")%^RESET%^");
          else tell_object(ob,"     %^BOLD%^%^WHITE%^%^"+capitalize(myfactions[j])+": %^RESET%^"+currentvalue+"%^RESET%^");
        }
      }
    }
    tell_object(ob,"\n%^RESET%^%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
}
