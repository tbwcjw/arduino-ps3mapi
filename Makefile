VERSION := $(shell grep '^version=' library.properties | cut -d'=' -f2)

LIB_NAME = ps3mapi
RELEASE = $(LIB_NAME)-$(VERSION).zip

EXCLUDE = "docs/*" \
		  ".vscode/*" \
          ".git/*" \
		  ".github/*" \
          ".gitignore" \
          "examples/internal/*" \
          "Makefile" \
		  "Doxyfile"

.PHONY: all release clean

all: release

release:
	@echo "Creating release archive $(RELEASE)..."
	zip -r $(RELEASE) . -x $(EXCLUDE)
	@echo "Release $(RELEASE) created."

clean:
	@echo "Cleaning up..."
	rm -f $(RELEASE)
