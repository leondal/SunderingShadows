// new factions command! Most of the work is done in the daemon, not here. N, 12/16.
#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_factions(string str){
    string playername,profilename,factionname;
    int adjustment;


    //find_object_or_load(FACTIONS_D);
    catch(call_other(FACTIONS_D,"??"));

    if(!stringp(str)) {
        FACTIONS_D->display_factions(TP,(string)TP->query_name());
        return 1;
    }
    if(avatarp(TP)) {
        if(sscanf(str,"%s adjust %s %s %d",playername,profilename,factionname,adjustment) == 4) {
            playername = lower_case(playername);
            profilename = lower_case(profilename);
            factionname = lower_case(factionname);
            if(!FACTIONS_D->has_faction(playername,profilename,factionname)) {
                tell_object(TP,"The player does not have the "+capitalize(factionname)+" faction activated on the "+profilename+" profile. You can only adjust active settings.");
                return 1;
            }
            if(!FACTIONS_D->adjust_faction(playername,profilename,factionname,adjustment)) {
                tell_object(TP,"Something in your syntax failed! Please see <help factions>.");
                return 1;
            }
            tell_object(TP,"You are attempting to adjust "+capitalize(playername)+"'s "+profilename+" profile with the "+factionname+" faction by "+adjustment+".");
            return 1;
        }
        if(sscanf(str,"%s %s",playername,profilename) == 2) {
            tell_object(TP,"Something in your syntax failed! Please see <help factions>.");
            return 1;
        }
        if(stringp(str)) {
            FACTIONS_D->display_factions(TP,str);
            return 1;
        }
    }
    tell_object(TP,"See <help factions> for syntax.");
    return 1;
}

int help(string str) {
    if(!avatarp(TP)) {
        tell_object(TP,"%^YELLOW%^Syntax: <factions>\n\n"
        "This command will provide you with your current standing with any in-game faction (cities, guilds, "
        "etc) with whom your character has interacted. These will range through the following ranks:%^RESET%^\n\n"

        "%^BOLD%^%^RED%^Hunted%^RESET%^: this faction may set a bounty for you, and/or actively try to apprehend "
        "or kill you, even beyond the limits of their usual domain.\n"
        "%^RESET%^%^RED%^Hostile%^RESET%^: this faction will actively try to repel or kill you, should you enter "
        "their territory.\n"
        "%^RESET%^%^ORANGE%^Unfriendly%^RESET%^: you have a poor reputation within this faction, but they will "
        "not actively seek to harm you.\n"
        "%^RESET%^%^CYAN%^Indifferent%^RESET%^: you hold no special regard or standing within this faction.\n"
        "%^RESET%^%^GREEN%^Friendly%^RESET%^: you are viewed in a positive light by members of this faction.\n"
        "%^RESET%^%^BLUE%^Respected%^RESET%^: members of this faction will actively treat you well, and may "
        "assist you in some circumstances.\n"
        "%^RESET%^%^MAGENTA%^Appointed%^RESET%^: you hold an official rank with the government or leadership "
        "of this faction, and its members may actively defend you or heed your directions.\n\n"

        "Please note: the underlying systems are being installed in phases, so not all of the above functionality "
        "is currently live, but will be progressively added in time.\n");
        return 1;
    }

    tell_object(TP,"%^YELLOW%^Syntax: <factions playername>\n\n"
    "This command will provide you with the current faction standings for that player, ranging through:\n\n"
    "%^BOLD%^%^RED%^Hunted%^RESET%^: bounty target, even beyond their territory. -6000 value only.\n"
    "%^RESET%^%^RED%^Hostile%^RESET%^: attack on sight within territory. Values -4000 to -5999.\n"
    "%^RESET%^%^ORANGE%^Unfriendly%^RESET%^: wary, but not actively hostile. Values -2000 to -3999.\n"
    "%^RESET%^%^CYAN%^Indifferent%^RESET%^: no special regard. Values 1999 to -1999.\n"
    "%^RESET%^%^GREEN%^Friendly%^RESET%^: friendly, but not specifically renowned. Values 3999 to 2000.\n"
    "%^RESET%^%^BLUE%^Respected%^RESET%^: specifically liked, has contacts/etc. Values 5999 to 4000.\n"
    "%^RESET%^%^MAGENTA%^Appointed%^RESET%^: official rank or leadership (HM only). 6000 value only.\n"
    "Values that attempt to set outside the -6000 to 6000 range will default to the furthest value possible and no more.\n");

    tell_object(TP,"%^YELLOW%^Syntax: <factions playername adjust profile faction value>\n\n"
    "Allows you to adjust a player's standing. Use with care! You must specify all items in the above syntax, "
    "as players have different ranks with each faction based on their profiles (to allow for shapeshifts, alter "
    "self, and disguise down the track). The value supplied is in addition to their current standing. This command "
    "will not function if they do not have an existing standing with that profile and faction. Please use <factions "
    "playername> to see what profiles & factions may be relevant.\n\n"
    "%^YELLOW%^Usage example: <factions bob adjust default tharis -200>%^RESET%^\n"
    "This will adjust Bob's standing with Tharis in his default (non-shifted, non-disguised) profile, decreasing "
    "his standing by 200 points.\n\n"
    "%^YELLOW%^Please note%^RESET%^: when player-directed adjustments are installed (later!), hunted and appointed "
    "ranks will be imm-granted only. At present, all ranks are imm-granted except for the automated start values.\n"
    "%^YELLOW%^Please note%^RESET%^: hunted and hostile ranks will be wiped on PK death, though hostile may re-apply "
    "thereafter on entering a faction area that is naturally hostile to the character type, eg/ elves in Tharis.\n\n");
    return 1;
}
