! Expanded on from http://fortranwiki.org/fortran/show/recursion
! gfortran -ffree-form AckermanFunction.f -o AckermanFunction

program ackermann
	integer :: argc, result, m, n, i, j, ack
	character(len=32) :: argv
	
	! Check the number of command line arguments
	argc = command_argument_count()
	if (.not. argc == 2) then 
		write(*,*) "ERROR: Call program as ./AckermannFunction M N"
		call exit(1)
	endif 
	! Get M and N from command arguments
	call get_command_argument(1, argv)
	read(argv, *) m
	call get_command_argument(2, argv)
	read(argv, *) n
	
	do i = 0, m
		do j = 0, n
			write(*,*) "Ackermann(", i , j, ") = ", ack(i,j)
		end do
	end do
	
end program ackermann

recursive function ack(m, n) result(a)
	integer, intent(in) :: m,n
	integer :: a
	if (m == 0) then
	 a=n+1
	else if (n == 0) then
	 a=ack(m-1,1)
	else
	 a=ack(m-1, ack(m, n-1))
	end if
end function ack