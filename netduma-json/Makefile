include $(TOPDIR)/rules.mk

PKG_NAME:=netduma-json
PKG_RELEASE:=$(AUTORELEASE)
PKG_VERSION:=1.0
SOURCE_DIR:=/home/eyi/Netduma/netduma-port-exercise
PKG_BUILD_DEPENDS:= +libjson-c
PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

TARGET_CFLAGSm:=+ -ljson-c

include $(INCLUDE_DIR)/package.mk

define Package/netduma-json
	SECTION:=practice-tests
	CATEGORY:=Netduma
	TITLE:=Netduma
	MAINTAINER:=EyitopeIO <adeyitope.io@gmail.com>
	MENU:=1
endef

define Package/description
	Use the force to parse JSON.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) -f $(SOURCE_DIR)/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/json-parser $(PKG_BUILD_DIR)/json-parser.c
endef

define Build/Clean
	rm -f $(PKG_BUILD_DIR)/o.*
	rm -f $(PKG_BUILD_DIR)/json-parser
endef

$(eval $(call BuildPackage,netduma-json))