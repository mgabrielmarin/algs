;; Quick sort implementation in Scheme
;; A LISP dialect

(define (quicksort array)
  (if (or (null? array)
	  (null? (cdr array)))
      array
      (let ((pivot (car array))
	    (rest (cdr array)))
	(append
	 (quicksort
	  (filter
	   (lambda (x) (< x pivot)) rest))
	 (list pivot)
	 (quicksort
	  (filter
	   (lambda (x) (>= x pivot)) rest))))))

;; Testing
(quicksort '(10 3847 384 63 84 82 95 3 7))
(quicksort '(11))
(quicksort '())
(quicksort '(8 3))

