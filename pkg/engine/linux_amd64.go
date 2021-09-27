//go:build linux && amd64
// +build linux,amd64

package engine

// #cgo CFLAGS: -I../../src/alsa
// #cgo LDFLAGS: -lasound
// #include "../../src/alsa/alsa.c"
import "C"

func List() {
	C.get_pcm_device_list()
}
