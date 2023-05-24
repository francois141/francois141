if (i++ > 1000) {
  dump(sd);
  USER_PANIC("Command not Ackd?");
}
barrelfish_usleep(1000);
if ((tc && cc) || (cc && !is_read && !is_write)) {
  break;
}
