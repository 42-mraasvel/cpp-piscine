NAME = phonebook

include makefile_settings/files.mk
include makefile_settings/settings.mk

all: $(NAME)

# Compilation
$(NAME): $(OBJ)
	$(CPP) -o $@ $^ $(CPPFLAGS)
$(OBJ): $(ODIR)/%.o: $(SDIR)/%.cpp
	@mkdir -p $(@D)
	$(CPP) -c -o $@ $< $(CPPFLAGS) $(IFLAGS)
$(DEP): $(DDIR)/%.d: $(SDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CPP) $< -MM -MF $@ -MT $(ODIR)/$*.o $(IFLAGS)

# Header dependency rules
-include $(DEP)

# Clean up
clean:
	$(RM) -r $(ODIR)
	$(RM) -r $(DDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all
