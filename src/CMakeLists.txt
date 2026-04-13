set(MakeCircleImages_SOURCE create_circles.cxx)
add_executable(MakeCircleImages_${MYHAWKID} ${MakeCircleImages_SOURCE})
target_link_libraries(MakeCircleImages_${MYHAWKID} ${ITK_LIBRARIES})

