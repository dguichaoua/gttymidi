#Déclaration du projet

project(gttymidi)
cmake_minimum_required(VERSION 2.8)


find_package(
	PkgConfig
)
pkg_check_modules(GTKMM gtkmm-3.0 )

link_directories(
    ${GTKMM_LIBRARY_DIRS} 
)

include_directories(
	${GTKMM_INCLUDE_DIRS} 
)  



#Génération de la liste des fichiers sources

file(

	GLOB_RECURSE

        source_files

        src/*
)

#Déclaration de l'exécutable
add_executable(

	gttymidi
 
       ${source_files}

)

target_link_libraries(gttymidi 
    	${GTKMM_LIBRARIES} 
	pthread
	asound
)

install(TARGETS gttymidi
	DESTINATION "bin"
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

install(FILES gttymidi.png
	DESTINATION "share"
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

