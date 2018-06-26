#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xdb0d8ebc, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xfc01da1c, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x88dc7e6f, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0x79c5a9f0, __VMLINUX_SYMBOL_STR(ioremap) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xc7e161b2, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xa28fb7c8, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x1b3b9517, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0xb87cadfc, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xf95913f2, __VMLINUX_SYMBOL_STR(input_register_device) },
	{ 0x8c6765af, __VMLINUX_SYMBOL_STR(input_mt_init_slots) },
	{ 0x307920e6, __VMLINUX_SYMBOL_STR(input_set_abs_params) },
	{ 0xf4e97b1a, __VMLINUX_SYMBOL_STR(rpi_firmware_property) },
	{ 0x6ee8ed38, __VMLINUX_SYMBOL_STR(dma_alloc_from_coherent) },
	{ 0x1dc6d519, __VMLINUX_SYMBOL_STR(input_allocate_device) },
	{ 0x40c57909, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0xdf59e464, __VMLINUX_SYMBOL_STR(rpi_firmware_get) },
	{ 0x3dd3f751, __VMLINUX_SYMBOL_STR(of_parse_phandle) },
	{ 0xb62b97fe, __VMLINUX_SYMBOL_STR(input_mt_report_pointer_emulation) },
	{ 0xa597ee71, __VMLINUX_SYMBOL_STR(input_mt_report_slot_state) },
	{ 0xa0fcd3fc, __VMLINUX_SYMBOL_STR(input_event) },
	{ 0x216d759a, __VMLINUX_SYMBOL_STR(mmiocpy) },
	{ 0xcc5005fe, __VMLINUX_SYMBOL_STR(msleep_interruptible) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xef742595, __VMLINUX_SYMBOL_STR(arm_dma_ops) },
	{ 0xedc03953, __VMLINUX_SYMBOL_STR(iounmap) },
	{ 0x519468b1, __VMLINUX_SYMBOL_STR(input_unregister_device) },
	{ 0x9d21406b, __VMLINUX_SYMBOL_STR(dma_release_from_coherent) },
	{ 0xd75ea86f, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x4d8b51ad, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Crpi,rpi-ft5406");
MODULE_ALIAS("of:N*T*Crpi,rpi-ft5406C*");

MODULE_INFO(srcversion, "63C38C12AD5D3B4AADD732E");
