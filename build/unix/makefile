CXX = g++

ROOTDR = ../../
INCDIR = ../../include
SRCDIR = ../../src
UTLDIR = ../../utilities
OBJDIR = obj

OBJ = $(OBJDIR)/EntityList.o $(OBJDIR)/Mesh.o $(OBJDIR)/MeshReader.o $(OBJDIR)/GidReader.o $(OBJDIR)/Point.o $(OBJDIR)/Element.o $(OBJDIR)/test.o

CXXOPTIONS = -g -std=c++17
CXXFLAGS = $(CXXOPTIONS) -I $(INCDIR)

default: $(OBJ)
	$(CXX) $(OBJDIR)/*.o -o Example
	./Example

$(OBJDIR)/EntityList.o: $(UTLDIR)/items/EntityList.cpp $(INCDIR)/*.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(OBJDIR)/Mesh.o: $(SRCDIR)/geometry/Mesh.cpp $(INCDIR)/*.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(OBJDIR)/MeshReader.o: $(UTLDIR)/interface/MeshReader.cpp $(INCDIR)/*.h 
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(OBJDIR)/GidReader.o: $(UTLDIR)/interface/GidReader.cpp $(INCDIR)/*.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(OBJDIR)/Point.o: $(SRCDIR)/geometry/Point.cpp $(INCDIR)/*.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(OBJDIR)/Element.o: $(SRCDIR)/elements/Element.cpp $(INCDIR)/*.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(OBJDIR)/test.o: $(ROOTDR)/tutorials/test/test.cpp $(INCDIR)/*.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)