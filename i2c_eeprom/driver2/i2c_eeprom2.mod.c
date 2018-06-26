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
	{ 0xd9ead207, __VMLINUX_SYMBOL_STR(i2c_del_driver) },
	{ 0xf204b815, __VMLINUX_SYMBOL_STR(i2c_register_driver) },
	{ 0x9b388444, __VMLINUX_SYMBOL_STR(get_zeroed_page) },
	{ 0x5bd65d83, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0xdc6883d2, __VMLINUX_SYMBOL_STR(sysfs_create_file_ns) },
	{ 0x240a67b, __VMLINUX_SYMBOL_STR(kobject_create_and_add) },
	{ 0x4eb8cc4b, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x25980599, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x39c30241, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x7b0d0d08, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x40c57909, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x9adaf3a8, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xae8c246d, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xf076f06e, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x5c547620, __VMLINUX_SYMBOL_STR(kobject_put) },
	{ 0x23ab3f1a, __VMLINUX_SYMBOL_STR(sysfs_remove_file_ns) },
	{ 0x871bbb3f, __VMLINUX_SYMBOL_STR(kernel_kobj) },
	{ 0x92a05b4c, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xe2e8065e, __VMLINUX_SYMBOL_STR(memdup_user) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x28cc25db, __VMLINUX_SYMBOL_STR(arm_copy_from_user) },
	{ 0xc58109f2, __VMLINUX_SYMBOL_STR(i2c_transfer) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0x5c7fba0e, __VMLINUX_SYMBOL_STR(remap_pfn_range) },
	{ 0x6a63b1c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x20ca31f3, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("i2c:eeprom");

MODULE_INFO(srcversion, "EE9A390DB3F4FA091E232EA");
