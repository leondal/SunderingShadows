//mapping_d.c

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

#define SAVE_FILE "/daemon/save/mappings"

mapping __SaveMappings;

void SAVE();

void create(){
  ::create();
  __SaveMappings = ([]);
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE);
  seteuid(getuid());
}

void set_value(string map_name, string name, string value){
  if(!__SaveMappings) __SaveMappings = ([]);
  if(!__SaveMappings[map_name]) __SaveMappings[map_name] = ([]);
	
  __SaveMappings[map_name][name] = value ;
  SAVE();
}

mapping query_mapping(string map_name){
  if(!__SaveMappings) __SaveMappings = ([]);
  if(!__SaveMappings[map_name]) __SaveMappings[map_name] = ([]);
	
  return __SaveMappings[map_name];
}
string * query_values(string map_name){
  if(!__SaveMappings) __SaveMappings = ([]);
  if(!__SaveMappings[map_name]) __SaveMappings[map_name] = ([]);
	
  return values(__SaveMappings[map_name]);
}
string * query_keys(string map_name){
  if(!__SaveMappings) __SaveMappings = ([]);
  if(!__SaveMappings[map_name]) __SaveMappings[map_name] = ([]);
	
  return keys(__SaveMappings[map_name]);
}

void remove_value_from_array(string map_name, string value) {
  mapping map;
  string name;
  int index;
  if(!__SaveMappings) __SaveMappings = ([]);
  if(!__SaveMappings[map_name]) __SaveMappings[map_name] = ([]);
  index = member_array(value, values(__SaveMappings[map_name]));
  if (index == -1)
    return;
  name = keys(__SaveMappings[map_name])[index];
  map = __SaveMappings[map_name];
  map_delete(map,name);
  __SaveMappings[map_name] = map;
  //  __SaveMappings[map_name] -= ({name});
  SAVE();
}

void remove_name_from_array(string map_name, string name){
  mapping map;
  if(!__SaveMappings) __SaveMappings = ([]);
  if(!__SaveMappings[map_name]) __SaveMappings[map_name] = ({});
  map = __SaveMappings[map_name];
  map_delete(map,name);
  __SaveMappings[map_name] = map;
  //  __SaveMappings[map_name] -= ({name});
  SAVE();
}

void remove_name(string name){
  string *map_names;
  mapping map;
  int i;
	
  map_names = keys(__SaveMappings);
	
  for(i = 0; i < sizeof(map_names);i++) {
    map = __SaveMappings[map_names[i]];
    map_delete(map,name);
    __SaveMappings[map_names[i]] = map;
    //		__SaveMappings[map_names[i]] -= ({name});
  }
  SAVE();
}

void remove_mapping(string nme){
  map_delete(__SaveMappings, nme);
  SAVE();
}

void SAVE(){
  seteuid(UID_DAEMONSAVE);
  save_object(SAVE_FILE);
  seteuid(getuid());
}

int is_member(string map_name, string name){
  if(!__SaveMappings) __SaveMappings = ([]);
  if(!__SaveMappings[map_name]) __SaveMappings[map_name] = ([]);
	
  return member_array(name, keys(__SaveMappings[map_name]));
}
