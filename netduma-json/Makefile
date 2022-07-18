include $(TOPDIR)/rules.mk

PKG_NAME:=netduma-json
PKG_RELEASE:=$(AUTORELEASE)
PKG_SOURCE_DATE:=2022_07_18
PKG_SOURCE_VERSION:=1.0.0

PKG_BUILD_DIR:=$(PKG_BUILD_DIR)/netduma-json
PKG_BUILD_DEPENDS:=+libjson-c

CFLAGS += -ljson-s

include $(INCLUDE_DIR)/package.mk

define Package/netduma-json
	CATEGORY:=Netduma
	DEPENDS:+libjson-c
	TITLE:=Netduma ecosystem
	MAINTAINER:=EyitopeIO <adeyitope.io@gmail.com>
	MENU:=1
endef

define Package/netduma-json/config
	source "$(SOURCE)/Config.in"
endef

define Package/description
	This packages makes eggs from ones and zeros. Studies show these eggs are more nutritious.
endef

define Build/Compile
	$(MAKE) 
endef

$(eval $(call BuildPackage,$(PKG_NAME)))