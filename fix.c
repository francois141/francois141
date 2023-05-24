if (i++ > 1000) {
  dump(sd);
  USER_PANIC("Command not Ackd?");
}
barrelfish_usleep(1000);
if ((tc && cc) || (cc && !is_read && !is_write)) {
  break;
}

// Code to test the fix
// Not in shdc.c
for(int k = 0; k < 10;k++) {
  for(int i = 2; i <= 30;i++) {
    debug_printf("Write read block : %d\n", i);
    for(int j = 0; j < 512;j++) {
      block[j] = (j + i) % 199;
    }
    assert(err_is_ok(write_block(b_driver, i, block)));
    assert(err_is_ok(read_block(b_driver, i, block2)));
    for(int j = 0; j < 512;j++) {
      assert(block[j] == block2[j]);
    }
  }
}
