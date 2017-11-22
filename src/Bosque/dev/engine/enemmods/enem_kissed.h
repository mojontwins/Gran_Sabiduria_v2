	// Throw a heart
	if ((rand8 () & 0x1f) == 1) heart_create ();

	// And move a bit

	// Frame
	rdc = (frame_counter >> 5);
	rda = rdc & 1;

	// Facing
	rdb = ((rdc >> 1) & 1) << 1;

	spr_id = en_s [gpit] + rda + rdb;
	enems_spr ();
