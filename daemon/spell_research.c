// Provides various reference data and algorithims
// for spell research.
// Thorn@ShadowGate
// 22 June 2001
// /daemon/spell_research.c

#include <std.h>
#include <security.h>
#include <spell_research.h>
#include <components.h>

// DEBUG mode enabled on 1, 0 is off.  Make sure and set DEBUGGER
// to yourself if you are testing this.
#define DEBUG 1

#define SAVE_FILE "/daemon/save/spell_research"

inherit DAEMON;

void SAVE();
void LOG(string msg);

int update_daemon();
private mapping get_data_from_file(string path);
mapping dump_spell_register();
private mapping get_data_from_file(string path);
private int is_valid_file(string filename);
private int get_next_id();
int generate_keyword_index();
int *get_spell_formula(int birthday, int id, int level);

// = ([ "name", "last update", "keywords", "level", "hide", "id" ])
// key = spell filename : ([ "name" = spell name, 
// "last update" = file modification date, "keywords" = ({ keywords })
// "level" = spell level, "hide" = 1|0 If 1 then don't allow this 
// spell to be researched (for new spells being tested), 
// "id" = unique ID of this spell for research purposes
mapping spell_register;
mapping keyword_index;
mapping schools;
int sequencer;

void create() {
    ::create();

  spell_register = ([]);
  sequencer = 1;
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE);
  seteuid(getuid());
  update_daemon();
}

void SAVE() {
  seteuid(UID_DAEMONSAVE);
  save_object(SAVE_FILE);
  seteuid(getuid());
}

void LOG(string msg) {
  seteuid(UID_LOG);
  log_file("spell_research", ctime(time())+": "+msg+"\n");
  seteuid(getuid());
}

// Get any changes to the wizard spell directory.  Find new spells
// that have been added.  Delete record of old spells.  Create 
// index to spell research keywords.
int update_daemon() {
	mapping new_register = ([ ]);
	mapping input = ([ ]);
	string *files;
	string filename, path;
	int i, filemod, regmod, sid, updates;
	
	if(!spell_register) spell_register = ([ ]);
	if(!schools) schools = ([ ]);
	updates = 0;
	
	// Get the list of spells in SPELL_DIRECTORY with last modification dates
	files = stat(SPELL_DIRECTORY);
	
	// Loop through the file names of the directory
	for(i=0;i<sizeof(files);i++) {
		filename = files[i];
		path = SPELL_DIRECTORY+filename;
		
		// Is this a spell file?  If not, move on to the next file name
		if(!is_valid_file(filename)) continue;
		
		// If the file exists in the spell_register do...
		if(input = spell_register[filename]) {
			filemod = stat(path)[1];
			regmod = input["last update"];
			
			// If the file has a different modification date than the 
			// registered file get the data from the file and put it
			// in new_register.
			if(filemod != regmod) {
				sid = input["id"];
				input = get_data_from_file(path);
				input["id"] = sid;
				schools[input["school"]] += 1;
				tell_object(find_player("thorn"), "Updates found in case 1.");
				tell_object(find_player("thorn"), "Path = "+path);
				tell_object(find_player("thorn"), "filemod = "+filemod);
				tell_object(find_player("thorn"), "regmod = "+regmod);
				updates = 1;
			}
						
			// If the file has the same modification date as the 
			// register move the data from the register into
			// new_register.
			// [REQUIRES NO CODE]
		}
			
		// Else if the file does not exist in the spell register,
		// then get the data from the file and put it into 
		// new_register.
		else {
			input = get_data_from_file(path);	
			if(input["name"] == 0) continue;
			else { 
				input["id"] = get_next_id();
				schools[input["school"]] += 1;
				updates = 1;
				tell_object(find_player("thorn"), "Updates found in case 2.");
				tell_object(find_player("thorn"), "Path = "+path);
			}
		}
				
		// Double check that its a spell
		if(input["name"] == 0) continue;
		
		// Add input to new_register	
		new_register[filename] = input;	
	
	}  // END LOOP
	
	// Replace the old register with the new register.
	spell_register = new_register;
	
	// If there are updates to the spell register, regenerate the
	// Keyword Index for researchers and other such things.
	if(updates == 1) {
		tell_object(find_player("thorn"), "Updates found.  Updating data....");
		generate_keyword_index();
	}
		
	// Save any updates
	TO->SAVE();
	
	return 1;
}

// Get the data we need from a spell file and then return it
// in a mapping with the fields defined for the spell register.
private mapping get_data_from_file(string path) {
	mapping retval = ([ ]);
	object spell;
	mixed *file_stat;
	
	if(spell = find_object(path)) {
		destruct(spell);
	}
	spell = new(path);
	file_stat = stat(path);
	
	retval["name"]        = spell->query_spell_name();
	retval["last update"] = (int)file_stat[1];
	retval["keywords"]    = spell->query_property("keywords");
	retval["level"]       = spell->query_spell_level();
	retval["hide"]        = spell->query_property("hide");
	retval["school"]      = spell->query_spell_sphere();
	
	spell->remove();
	return retval;	
}

// Is the file in question a spell file we can look at?
private int is_valid_file(string filename) {
	string temp, temp2;
	int retval;
	retval = sscanf(filename, "_%s.%s", temp, temp2);	
	if(retval < 2) return 0;
	if(!strcmp("c", temp2)) return 1;
	return 0;
}

// Get the next valid id from the sequencer variable
private int get_next_id() {
	int retval;
	
	if(!sequencer) sequencer = 1;
	retval = sequencer;
	sequencer++;
	TO->SAVE();
	return retval;	
}

// Just dump the spell register so that it can be inspected
// for debugging or an information command.
mapping dump_spell_register() { return spell_register; }

// Just dump the school list so that it can be inspected
// for debugging or an information command.
mapping dump_schools() { return schools; }

// Clear the register out and start from scratch
// This should NEVER be used when in production unless you
// are ABSOLUTELY certain about what you are doing.
int clear_register() {
	spell_register = ([ ]);
	keyword_index = ([ ]);
	schools = ([ ]);
	sequencer = 1;
	TO->SAVE();
	return 1;
}

// Generates the index of keywords to each spell that it is
// found in.
int generate_keyword_index() {
	mapping new_index = ([ ]);
	mapping record = ([ ]);
	string *keyz;
	string *list;
	string words;
	string word;
	int i, j;
	
	if(!keyword_index) keyword_index = ([ ]);
	keyz = keys(spell_register);
	for(i=0;i<sizeof(keyz);i++) {
		record = spell_register[keyz[i]];
		words = record["keywords"];
		if(!words) continue;
		for(j=0;j<sizeof(words);j++) {
			list = new_index[words[j]];
			if(!list) keyword_index[words[j]];
			if(!list) list = ({ });
			if(member_array(keyz[i], list) == -1)
				list += ({ keyz[i] });
			new_index[words[j]] = list;
		}
	}
	keyword_index = new_index;
	return 1;
}

// Returns all of the spells that fit the particular
// keywords that are entered.
string *get_spells_from_keywords(string school, string *keywords) {
	int numwords, i, j;
	mapping unifier = ([ ]);
	string *files;
	string *retval = ({ });
	mapping info; 
	
	if(!keywords) return ({ });
	numwords = sizeof(keywords);
	for(i=0;i<numwords;i++) {
		files = keyword_index[keywords[i]];
		for(j=0;j<sizeof(files);j++) {
			info = spell_register[files[j]];
			if(info["school"] != school)
				continue;
			unifier[files[j]]++;
		}
	}
	
	files = keys(unifier);
	for(i=0;i<sizeof(files);i++) {
		if(unifier[files[i]] == numwords) 
			retval += ({ files[i] });
	}
	return retval;
}

// Returns all keywords that are currently known.
string *get_keywords() {
	if(!keyword_index) return ({ });
	return keys(keyword_index);
}

int *get_spell_formula(int birthday, int id, int level) {
	int num = sizeof(ELEMENTS);
	int day, past, current, elem, i;
	int *retval = ({ });
	int *primes = ({ 2, 3, 5, 7, 13, 17, 19, 31, 67, 127, 257 });
	int *rprimes = ({ 257, 127, 67, 31, 19, 17, 13, 7, 5, 3, 2 });
	int x, y;
	float pi = 3.14159;
	
	day = birthday;
	switch(day % 6) {
		case 0:
		past = id;
		current = id;
		day += id;
		break;
		case 1:
		past = day;
		current = id;
		break;
		case 2:
		day *= to_int(cos(to_float(id)));
		past = id;
		current = 90;
		break;
		case 3:
		day += (level * 7);
		past = id;
		current = id;
		break;
		case 4:
		day += (id * 7);
		past = 435;
		current = 944;
		break;
		case 5:
		day += (17 * level);
		past = id;
		current = id * 3;
		break;
		default:
		past = 90;
		current = 180;
		break;
	}
	for(i=0;i<=level;i++) {
		day += (current + past);
		elem = day % num;
		retval += ({ elem });
		x = day % 11;
		if(x == 10) x = level;
		past = current;
		current = current + primes[x] + level;
		day += rprimes[x];
	}
	return retval;
}

int *get_formula_by_name(object searcher, string name) {
	string file;
	string *keyz;
	mapping record;
	int i, id, level;
	
	keyz = keys(spell_register);
	for(i=0;i<sizeof(keyz);i++) {
		record = spell_register[keyz[i]];
		if(record["name"] == name) {
			id = record["id"];
			level = record["level"];
			return get_spell_formula((int)searcher->query_birthday(), id, level);
		}
	}
	return 0;
}

// Return the n-th element in the formula array for a spell for
// a particular character.  n = [0..sizeof(formula)-1] 
int get_formula_element(object user, string file, int n) {
	int *formula;
	int id, level;
	mapping info;
	
	info = spell_register[file];
	if(n > info["level"]) return -1;
	formula = get_spell_formula((int)user->query_birthday(), info["id"], info["level"]);
	return formula[n];
}

string code2word(int x) { return ELEMENTS[x]; }

int word2code(string word) {
	return member_array(word, ELEMENTS);
}

// Pick out a random spell in the school selected.
string get_random_spell(string school) {
	int j, r;
	mapping info, unifier;
	string *files = keys(spell_register);
	string *selected;
	
	unifier = ([ ]);
	for(j=0;j<sizeof(files);j++) {
		info = spell_register[files[j]];
		if(info["school"] != school)
			continue;
		unifier[files[j]]++;
	}
	
	selected = keys(unifier);
	r = sizeof(selected);
	if(!r) return 0;
	return spell_register[selected[random(r)]]["name"];
}

// Put in the spell name (not file name) of a spell
// and get back its sphere.  Yes, we can do that by 
// querying the spell object, but this allows us to
// do it without loading a spell object and also 
// without having to convert the spell name into the
// file name.
string get_spell_sphere(string name) {
	string file;
	string *keyz;
	mapping record;
	int i, id, level;
	
	keyz = keys(spell_register);
	for(i=0;i<sizeof(keyz);i++) {
		record = spell_register[keyz[i]];
		if(record["name"] == name)
			return record["school"];
	}
	return 0;
}	

// Put in the spell name (not file name) of a spell
// and get back its level.  Same reasoning as above.
int get_spell_level(string name) {
	string file;
	string *keyz;
	mapping record;
	int i, id, level;
	
	keyz = keys(spell_register);
	for(i=0;i<sizeof(keyz);i++) {
		record = spell_register[keyz[i]];
		if(record["name"] == name)
			return record["level"];
	}
	return 0;
}	

int valid_school(string school) {
	string *slist = keys(schools);
	if(member_array(school, slist) != -1) return 1;
	return 0;
}

int school_size(string school) {
	if(!valid_school(school)) return 0;
	return schools[school];
}
