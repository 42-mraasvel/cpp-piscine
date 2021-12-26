include ./makefile_settings/files.mk
include ./makefile_settings/settings.mk

# Rules
.PHONY: all
all:
	$(MAKE) -j4 $(NAME)

# Compilation
$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LFLAGS)
$(OBJ): $(ODIR)/%.o: $(SDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)
$(DDIR)/%.d: $(SDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(ODIR)/$*.o $(IFLAGS)

# Cleanup
.PHONY: clean fclean re cleanall
clean:
	$(RM) -r $(ODIR)
	$(RM) -r $(DDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

# Debug
.PHONY: debug
debug: fclean
	$(MAKE) all DEBUG=1


-include $(DEP)
