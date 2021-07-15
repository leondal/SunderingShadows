#define MELEEFEATS ({"MeleeDamage","MeleeAccuracy","TwoHandedWeapons","WeaponAndShield","TwoWeapons","Evasion","Horsemanship","RangedCombat","GeneralCombat","WeaponMastery", "Rampage","SavageCombat", "KiOffense", "KiDefense", "UnarmedCombat", "KiEnhancement","Duelist","DamageResistance", "ArmorMastery"})
#define SPELLFEATS ({"MagicDamage","MagicAccuracy","MagicProtection","ArcaneSpellcraft","DivineSpellcraft","WildernessLore","Psionics","Inquisition","MagicResistance","MetaMagic"})
#define GENERALFEATS ({"MagicResistance","DamageResistance","NonCombat","Performance","Presence", "Racial"})
#define MAGUSFEATS ({"MagusArcana", "Steel&Magic"})
#define PALADINFEATS ({"DivineBond"})
#define RAGEFEATS ({ "RagePower" })
#define TALENTFEATS ({ "RogueTalent" })
#define PRESTIGE_FEATS ({"ArcaneArcher","ArcaneTrickster","Archdruid","Archmage","Archpsion","Assassin","BeastMastery","Bladeweaver","Chronicler", "CryptStalker", "EldritchKnight", "PrestigeDuelist", "GrandmasterOfTheWay", "HellfireWarlock", "Hierophant", "ImmortalDefender", "Metamind", "Mindblade", "PaleLord", "PrimevalChampion","RadiantServant", "RageProphet", "ShadowAdept", "Shadowdancer", "TomeBoundMaster", "VersatileArcanist", "Warmaster", "Warmind","Gravecaller", "Cypher", "VampireLord", "RisenMartyr"})
#define PRESTIGE_MAP (["RadiantServant" : "radiant_servant", "Archmage" : "archmage", "BeastMastery" : "beast_master", "Chronicler" : "chronicler", "CryptStalker" : "crypt_stalker", "PrestigeDuelist" : "duelist", "ShadowAdept" : "shadow_adept", "Shadowdancer" : "shadowdancer", "VersatileArcanist" : "versatile_arcanist", "Archdruid" : "archdruid", "PrimevalChampion" : "primeval_champion", "Metamind" : "metamind", "Warmind" : "warmind", "Archpsion" : "archpsion", "ImmortalDefender" : "immortal_defender", "GrandmasterOfTheWay" : "grandmaster_of_the_way", "HellfireWarlock" : "hellfire_warlock", "Bladeweaver" : "bladeweaver", "Warmaster" : "warmaster", "Mindblade" : "mindblade", "Hierophant" : "hierophant", "EldritchKnight" : "eldritch_knight", "ArcaneArcher": "arcane_archer", "RageProphet" : "rage_prophet", "ArcaneTrickster" : "arcane_trickster", "Gravecaller":"gravecaller", "Assassin":"assassin", "Cypher":"cypher", "TomeBoundMaster" : "tome_bound_master","VampireLord":"vampire_lord","RisenMartyr":"risen_martyr"])

#define EPICFEATS ({"EpicFeats" })
#define SHIFTING_CLASSES ({"druid" })

#define FEATS_FILE "/cmds/feats/"
#define FEAT_FILE "/cmds/feats/"

#define FEAT_HEADER "\n%^RESET%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^> %^BOLD%^%^GREEN%^Feats %^RESET%^<%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^"
#define FEAT_FOOTER "\n%^RESET%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
#define IDT " "
#define LEVEL_SPACER 5
#define ALIGN_SPACER 39 - strlen(IDT)
#define FEAT_SPACER 33 - strlen(IDT)

#define FEAT_TYPES ({ "racial", "martial", "spellcraft", "hybrid", "arcana", "divinebond", "rage" })

/*
#define HYBRIDFEATS ({"MeleeDamage","MeleeAccuracy","TwoHandedWeapons","WeaponAndShield","TwoWeapons","Evasion","Horsemanship","Archery","GeneralCombat", "WeaponMastery","Rampage","KiEnhancement", "SavageCombat","MagicDamage","MagicAccuracy","MagicProtection","ArcaneSpellcraft","DivineSpellcraft","WildernessLore","Psionics" })
*/
