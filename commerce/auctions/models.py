from django.contrib.auth.models import AbstractUser
from django.db import models


class User(AbstractUser):
    pass


class Auction(models.Model):

    # Categories
    MOTORS = "MOT"
    FASHION = "FAS"
    ELECTRONICS = "ELE"
    ARTS = "ART"
    HOME_GOODS = "HOM"
    SPORTING_GOODS = "SPO"
    TOYS = "TOY"
    STATIONARY = "STA"
    MUSIC = "MUS"

    CATEGORY = [
        (MOTORS, "Motors"),
        (FASHION, "Fashion"),
        (ELECTRONICS, "Electronics"),
        (ARTS, "Art"),
        (HOME_GOODS, "Home Goods"),
        (SPORTING_GOODS, "Sporting Goods"),
        (TOYS, "Toys"),
        (STATIONARY, "Stationary"),
        (MUSIC, "Music"),
        ]

    # Model fields
    # auto: auction_id
    seller = models.ForeignKey(User, on_delete=models.CASCADE)
    title = models.CharField(max_length=64, blank=False)
    description = models.TextField(blank=True)
    current_price = models.DecimalField(max_digits=11, decimal_places=2, default=0.0)
    category = models.CharField(max_length=3, choices=CATEGORY, default=MOTORS)
    image_url = models.URLField(blank=True)
    publication_date = models.DateTimeField(auto_now_add=True)
    closed = models.BooleanField(default=False)

    class Meta:
        verbose_name = "auction"
        verbose_name_plural = "auctions"

    def __str__(self):
        return f"Auction id: {self.id}, title: {self.title}, seller: {self.seller}"

class Bid(models.Model):

    # auto: bid_id
    auction = models.ForeignKey(Auction, on_delete=models.CASCADE)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    bid_date = models.DateTimeField(auto_now_add=True)
    bid_price = models.DecimalField(max_digits=11, decimal_places=2)

    class Meta:
        verbose_name = "bid"
        verbose_name_plural = "bids"

    def __str__(self):
        return f"{self.user} bid {self.bid_price} $ on {self.auction}"


class Comment(models.Model):
    # Model fields
    # auto: comment_id
    auction = models.ForeignKey(Auction, on_delete=models.CASCADE)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    comment = models.TextField(blank=False)
    comment_date = models.DateTimeField(auto_now_add=True, null=True)
    class Meta:
        verbose_name = "comment"
        verbose_name_plural = "comments"

    def __str__(self):
        return f"Comment {self.id} on auction {self.auction} made by {self.user}"