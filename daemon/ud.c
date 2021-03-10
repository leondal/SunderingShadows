// Unique Items Daemon
// Ensures that only one copy of a unique
// item is cloneable at once and only if
// that object does not reside in an interactive
// player's saved inventory
// Thorn@ShadowGate
// 27 June 2000
// /daemon/unique_d.c

#include <std.h>
#include <security.h>

#define SAVE_FILE "/daemon/save/unique"

// The default lease period is 15 days
#define DEFAULT_LEASE 1296000
#define OWNER 0
#define LEASE_END 1
#define EMPTY_LEASE ({ "no owner", 0 })

inherit DAEMON;

mapping item_data;

void SAVE();
void LOG(string msg);
int ok_to_clone(string unique_id, object requestor);
string query_owner(string unique_id);
int query_lease_end(string unique_id);
varargs int issue_lease(string unique_id, string user_name, int custom_lease);
int clear_lease(string unique_id);
int register_item(string unique_id);
int unregister_item(string unique_id);
mixed *list_unique_items();
int is_registered(string unique_id);
int num_unique_items();
int update_daemon();
mixed *get_lease(string unique_id);

void create() {
    ::create();

  item_data = ([]);
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
  log_file("unique_items", ctime(time())+": "+msg+"\n");
  seteuid(getuid());
}

// Returns 1 if it is okay to clone this item, 0 if not.
int ok_to_clone(string unique_id, object requestor) {
  mixed *tmp;
  int lease_end;
  string owner;
  int now = time();
  
  tmp = get_lease(unique_id);
  if(tmp == ({ 0 })) { return 1; }
  if(tmp == EMPTY_LEASE) { return 1; }
    
  lease_end = tmp[LEASE_END];
  owner = tmp[OWNER];
  
  if(now > lease_end) {
    clear_lease(unique_id);
    return 0;
  }
  if(!userp(requestor)) return 0;
  if((string)requestor->query_name() != owner) return 0;
  LOG("Successfully cloned "+unique_id+" for "+requestor->query_cap_name());
  return 1;
}

// Return the owner name
string query_owner(string unique_id) {
  mixed *tmp;
  
  if(!is_registered(unique_id)) { return "No such item."; }
  tmp = item_data[unique_id];
  return tmp[OWNER];
}

// Return the lease end date in seconds since the epoch
int query_lease_end(string unique_id) {
  mixed *tmp;
  
  if(!is_registered(unique_id)) { return -1; }
  tmp = item_data[unique_id];
  return tmp[LEASE_END];
}

varargs int issue_lease(string unique_id, string user_name, int custom_lease) {
  int this_lease;
  int lease_end;
  mixed *this_entry;
  
  if(!unique_id || !user_name) {
    return notify_fail("Missing a required argument to: issue_lease()");
  }
  if(!is_registered(unique_id)) {
    return notify_fail("No such item registered error in: issue_lease()");
  }
  if(!custom_lease || custom_lease <= 0) {
    this_lease = DEFAULT_LEASE;
  }
  lease_end = time();
  lease_end += this_lease;
  this_entry = ({ user_name, lease_end });
  item_data[unique_id] = this_entry;
  LOG("Lease of \'"+unique_id+"\' to "+capitalize(user_name)+" until "
    +ctime(lease_end));
  SAVE();
  return 1;
}

// Clear the lease on this item so it is okay to clone
int clear_lease(string unique_id) {
  if(!is_registered(unique_id)) {
    return notify_fail("No such item registered error in: clear_lease()");
  }
  item_data[unique_id] = EMPTY_LEASE;
  return 1;
}

// Add a new empty item to this daemon's consideration
int register_item(string unique_id) {
  if(is_registered(unique_id)) {
    return notify_fail("Item already registered error in: register_item()");
  }
  item_data[unique_id] = EMPTY_LEASE;  
  LOG("Registered "+unique_id+" as a unique item.");
  SAVE();
  return 1;
}

// Delete an item from this daemon's consideration
int unregister_item(string unique_id) {
  if(!is_registered(unique_id)) {
    return notify_fail(
      "No such item registered error in: unregister_item()"
    );
  }
  map_delete(item_data, unique_id);
  LOG("Unregistered "+unique_id+" as a unique item.");
  SAVE();
  return 1;
}

// Return an array with all of the item_data info
string *list_unique_items() {
  int inc;
  string *ikeys;
  int numkeys;
  string *value;
  string *retval = ({ });
  string owner;
  string key;
  int lease_end;
  
  update_daemon();
  ikeys = keys(item_data);
  numkeys = sizeof(ikeys);
  for(inc=0;inc<numkeys;inc++) {
    key = ikeys[inc];
    value = item_data[key];
    
    lease_end = value[LEASE_END];
	if(!lease_end) lease_end = "n/a";
	else lease_end = ctime(lease_end);
    owner = value[OWNER];
	retval += ({ key+"		"+owner+"	"+lease_end });
  }
  return retval;
}

int is_registered(string unique_id) {
  return !undefinedp(item_data[unique_id]);
}

mixed *get_lease(string unique_id) {  
  if(!is_registered(unique_id)) {
    register_item(unique_id);
  }
  return item_data[unique_id];
}

int num_unique_items() {
  return sizeof(keys(item_data));
}

// Goes through the all of the leases and expires the leases
// of items that have passed their expiration date, expires
// leases to rid or suicided players and unregisters any items
// that no longer exist at the path indicated.  
// Run this at create time to collect the garbage and also
// run when listing the leases in order to give an up-to-date
// listing of valid leases.  
int update_daemon() {
  int inc;
  string *ikeys = keys(item_data);
  int numkeys = sizeof(ikeys);
  mixed *value;
  string owner;
  int lease_end;
  string *name;
  string initial;
  int now = time();
  
  LOG("Beginning daemon update....");
  for(inc=0;inc<numkeys;inc++) {
    
    if(!file_exists(ikeys[inc])) {
      unregister_item(ikeys[inc]);
      continue;
    }
    value = item_data[ikeys[inc]];
    
    lease_end = value[LEASE_END];
    owner = value[OWNER];
  
    if(now > lease_end) {
      clear_lease(ikeys[inc]);
      continue;
    }
    name = explode(owner, "");
    initial = name[0];
    if(!file_exists("/adm/save/users/"+initial+"/"+owner+".o")) {
      LOG("The player, "+owner+", no longer exists.  Clearing lease.");
      clear_lease(ikeys[inc]);
      continue;
    }
  }
  SAVE();
  LOG("Daemon update complete.");
}
